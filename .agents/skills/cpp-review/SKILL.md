---
name: cpp-review
description: >
  Review C++ code - a diff, a pull request, or a file - against the C++ Best Practices checklist popularized by Jason
  Turner (`lefticus`): undefined behaviour and lifetime bugs first, then ownership, const-correctness, interface
  design, and only then style. Use when asked to review, critique, or audit C++ code, when triaging a C++ pull
  request, or when a C++ build is warning-clean but you still do not trust it. Prescribes running the tools
  (warnings, clang-tidy, sanitizers) before reading, so the review spends its attention on what tools cannot see.
license: Apache-2.0
---

# C++ Review

Use this skill when reviewing C++ - a working diff, a PR, or a file someone asked you to look at.

## Rule zero: run the tools before you read

Anything a machine can find is not worth a human comment. Before reviewing, try in order (skip what the project has
not configured, and say so in the review):

1. Build with the project's warnings at maximum; read every new warning the change introduces.
2. `clang-tidy` on the changed files only (`clang-tidy --line-filter=...`, or `run-clang-tidy` scoped to the diff).
3. `cppcheck --enable=all` on the changed translation units.
4. Run the tests under **ASan+UBSan**, and under **TSan** if any threading is touched. A green test suite without
   sanitizers proves very little in C++.

Report what you ran and what you could not run. A review that says "tests pass" when sanitizers were never enabled is
overstating its evidence.

## Then read, in this priority order

Comment on the first category that fires. Do not bury a lifetime bug under nits about naming.

### 1. Undefined behaviour and lifetime

- Dangling references: a `const&` or `string_view`/`span` parameter stored in a member, captured by a lambda that
  outlives the call, or bound to a temporary. `auto&& x = f().g();` is a classic.
- Iterator/reference invalidation: a container mutated while iterated, or a reference held across a `push_back`.
- Out-of-bounds indexing, `.front()`/`.back()`/`operator[]` on a possibly-empty container, `*` on an empty
  `optional`.
- Signed overflow, shifts by >= width, unaligned or type-punning `reinterpret_cast` (use `std::bit_cast` or
  `memcpy`).
- Uninitialized members - especially a constructor that assigns in the body instead of the member-init list, or a new
  member added to an existing constructor and forgotten.
- Order-of-initialization dependence between static objects in different translation units.
- Anything returning a pointer or reference to a local.

### 2. Ownership and resources

- Naked `new`/`delete`, owning raw pointers, or manual `close`/`free` where RAII would do.
- `shared_ptr` used where `unique_ptr` or a plain value would do; `shared_ptr` cycles; `shared_ptr` copied by value
  into a function that only observes.
- Rule of zero/five violations: a user-declared destructor (or copy ctor, or assignment) that silently disables move
  operations and turns every "move" in the codebase into a copy.
- Resources acquired on one path and released on another - if an exception can be thrown between them, it leaks.
- Exception safety: does the function leave the object in a valid state if a mid-way operation throws? Is the strong
  guarantee claimed but not delivered?

### 3. Correctness of the interface

- Signatures that admit wrong calls: two adjacent `int` parameters, `bool` flags, `std::string` where a
  `std::filesystem::path` or a strong type belongs.
- Missing `explicit` on a single-argument constructor; implicit conversions that the caller did not ask for.
- Missing `const` on member functions; `mutable` members without a matching mutex (see `cpp-concurrency`).
- `[[nodiscard]]` missing on a function whose return value must not be dropped.
- Error reporting a caller can ignore: a returned status code with no `[[nodiscard]]`, or a swallowed exception.
- `override` missing on an override; a base class with virtual functions and a public non-virtual destructor.

### 4. Clarity and cost

- Raw loops that a named algorithm (`std::ranges::find_if`, `any_of`, `transform`, `accumulate`) would state better.
- Copies that could be moves or references: unnecessary temporaries, `push_back` in a loop without `reserve`,
  by-value capture of a large object in a lambda.
- Macros doing what `constexpr`, templates, or `if constexpr` would do.
- C-style casts.
- Variables declared far from first use, or declared uninitialized then assigned.
- Dead flexibility: an interface with one implementation, a template parameter with one instantiation, a
  configuration knob nothing sets.

### 5. Tests

- Does the change have a test that fails without it? For a bug fix, does the test reproduce the original bug?
- Boundaries: empty container, single element, maximum size, self-assignment, self-move.
- If the code parses untrusted input, is there a fuzz target?

## Writing the review

- One finding per comment, anchored at `file:line`, stating the concrete failure - the input or interleaving that
  produces the wrong result - not a rule number.
- Separate "this is a bug" from "I would write this differently". Do not let the second crowd out the first.
- If a suggestion is a matter of taste and the codebase is internally consistent, drop it. Consistency with the
  surrounding code beats consistency with any style guide.
- If you could not verify a suspicion (no repro, no sanitizer run), say it is a suspicion.

## Sources

Checklist derived from Jason Turner's [C++ Best Practices](https://github.com/cpp-best-practices/cppbestpractices)
(CC BY-NC 4.0 - referenced, not reproduced), the tooling defaults in
[`cmake_template`](https://github.com/cpp-best-practices/cmake_template), and the
[C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines). For the practices being reviewed
against, see `cpp-best-practices`; for threading review, see `cpp-concurrency`.
