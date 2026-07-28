---
name: cpp-best-practices
description: >
  Write modern C++ the way the C++ Best Practices community (Jason Turner / `lefticus`) teaches it - const-correct,
  RAII-only ownership, algorithms over raw loops, strong types over stringly-typed interfaces, and a build that turns
  the compiler and sanitizers into the first line of defence. Use when writing, refactoring, or scaffolding C++ code,
  picking between `unique_ptr`/`shared_ptr`/value semantics, choosing warning and sanitizer flags, or deciding which
  language feature to reach for.
license: Apache-2.0
---

# C++ Best Practices

Use this skill when authoring or refactoring C++, or when setting up the build so mistakes fail loudly instead of
silently.

## The order of operations

1. **Make the tools catch it.** Any rule below that a compiler flag, a clang-tidy check, or a sanitizer can enforce
   should be enforced there, not in review. Configure that first.
2. **Make it correct.** Types that cannot represent the wrong thing beat runtime checks.
3. **Make it clear.** Standard algorithms and value semantics over hand-rolled loops and pointers.
4. **Then, only if measured, make it fast.**

## Turn the compiler into a static analyzer

Baseline that should be on for every target - the `cpp-best-practices/cmake_template` defaults, plus `-Wsign-conversion`
from the book's tooling chapter.

```text
GCC/Clang: -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused
           -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference
           -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough
GCC also:  -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op
           -Wuseless-cast -Wsuggest-override
MSVC:      /W4 /permissive- (plus the off-by-default /w14xxx set: 4242 4254 4263 4265 4287 4289
           4296 4311 4545 4546 4547 4549 4555 4619 4640 4826 4905 4906 4928)
```

Rules of thumb:

- `-Werror` in CI, not necessarily in a developer's local build.
- Suppress a warning at the narrowest possible scope, with a comment saying why. A project-wide `-Wno-` is a decision
  to stop being told about a whole class of bug.
- Dependencies are not your code: include them as `SYSTEM` so their headers do not drown your warnings.

Then add, in rough order of value per unit of effort: **clang-tidy** (`Checks: "*"` minus the vendor-specific
`abseil-*`, `altera-*`, `android-*`, `fuchsia-*`, `google-*`, `llvm*`, `zircon-*` groups plus
`modernize-use-trailing-return-type`), **ASan+UBSan** and **TSan** builds in CI, **cppcheck `--enable=all`**, and a
**libFuzzer** target for anything that parses untrusted input. Hardening (`_FORTIFY_SOURCE=3`,
`-D_GLIBCXX_ASSERTIONS`, `-fstack-protector-strong`, control-flow guard) belongs in release builds, not just debug.

## Ownership and memory

- No naked `new`/`delete`, no owning raw pointers. `std::unique_ptr` by default; `std::shared_ptr` only when ownership
  is genuinely shared and you can name the second owner.
- Build them with `std::make_unique` / `std::make_shared` - one allocation instead of two, and exception-safe.
- Return `unique_ptr` from factories. A caller who needs sharing can convert; the reverse is not possible.
- `std::array` or `std::vector` instead of C arrays; `std::span` to pass a non-owning view of either. Never
  `shared_ptr<T[]>`.
- A raw pointer or reference in a signature means "I observe this, I do not own it", and must not outlive the callee.

## Const and the shape of interfaces

- `const` on everything that is not mutated: locals, member functions, references. It documents intent and unlocks
  optimizations.
- Pass cheap types (`int`, `double`, enums, `string_view`, `span`) **by value**. Pass expensive types by `const&`. A
  `const int&` parameter is a pessimization.
- Prefer returning by value; it is move-friendly and thread-safe. Return `const&` from a getter only when the normal
  use is observation and the lifetime is obvious.
- Mark single-argument constructors `explicit` unless implicit conversion is a designed feature.
- Avoid `bool` parameters - `draw(shape, true)` tells the reader nothing. Use a scoped enum or split the function.
- Avoid stringly-typed interfaces. `std::filesystem::path` beats `std::string` for a path; a strong typedef beats
  `int` for an ID. Types that cannot be mixed up will not be mixed up.

## Language usage

- `static_cast` / `dynamic_cast` / `const_cast` / `reinterpret_cast`, never a C-style cast. They are checked and they
  are greppable.
- `constexpr` (and `consteval`, `constinit`) instead of macros for constants; templates and `if constexpr` instead of
  macros for logic. The preprocessor is invisible to the debugger.
- Declare variables as late as possible and initialize them at declaration. Use `if (auto x = f(); cond)` init
  statements to keep scope tight.
- Use `override` on every override and `final` where a hierarchy is closed. Do not repeat `virtual` on an override.
- Follow the rule of zero: let a class own resources through members that already manage themselves, and declare none
  of the five special members. If you must declare one, declare all that apply - declaring a destructor suppresses the
  implicit move operations and silently turns moves into copies.
- Never put a side effect inside `assert` - it evaporates in release builds. Assign to a `[[maybe_unused]]` local and
  assert on that.
- Prefer `++i` to `i++` when the result is unused, `'\n'` to `"\n"`, and `"\n"` to `std::endl` (which forces a flush).
- Use a lambda, not `std::bind`.
- Prefer exceptions to error codes when failure is exceptional; prefer `std::optional` / `std::expected` when it is
  not. Either way, do not return a code that a caller can silently ignore.

## Replace raw loops with algorithms

Treat a hand-written loop over a container - and especially an `operator[]` inside one - as a smell. Reach for
`<algorithm>` and `<numeric>`, and for the C++20 ranges versions where available: `std::ranges::sort`,
`find_if`, `any_of`/`all_of`/`none_of`, `transform`, `accumulate`/`reduce`, `views::filter`, `views::transform`.
Named algorithms state the intent, come with the right complexity, and are already correct at the boundaries.

## Performance, in the right order

Never optimize without a profile. Once you have one:

- Fix the algorithm and the data layout first; micro-optimizations cannot rescue an O(n²) scan or a pointer-chasing
  layout.
- Kill temporaries and copies. `reserve()` before a loop that pushes. Prefer initializer lists to repeated
  `push_back`. `emplace_back` to construct in place.
- `shared_ptr` copies are atomic refcount traffic - pass `const shared_ptr&`, or better, pass the underlying reference.
- Heap allocation is the usual hidden cost. Prefer stack and value semantics; consider `std::pmr` arenas for
  allocation-heavy hot paths.
- Build times are performance too: forward declare instead of including, keep templates thin, and run
  `include-what-you-use`.

## Sources

The practices above summarize the community consensus documented in Jason Turner's
[C++ Best Practices](https://github.com/cpp-best-practices/cppbestpractices) book (CC BY-NC 4.0 - referenced, not
reproduced), the [`cmake_template`](https://github.com/cpp-best-practices/cmake_template) project defaults, and the
[C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines). See also
[C++ Weekly](https://github.com/lefticus/cpp_weekly). For review workflow use `cpp-review`; for threading use
`cpp-concurrency`.
