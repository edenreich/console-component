---
name: cpp-concurrency
description: >
  Write and review concurrent C++ the way the C++ Best Practices community (Jason Turner / `lefticus`) frames it -
  design shared state away first, then use `std::jthread`, scoped locks, the mutex-and-mutable rule, and
  ThreadSanitizer to make what is left provably safe. Use when adding threads, thread pools, async work, or atomics,
  when diagnosing a data race, deadlock, or heisenbug, when choosing between `jthread`/`async`/executors, or when
  reviewing code that shares mutable state.
license: Apache-2.0
---

# C++ Concurrency

Use this skill when adding, reviewing, or debugging threaded C++.

## Design the sharing away first

Most concurrency bugs are the consequence of an ownership decision made long before the first `std::thread`.

- **Avoid global data.** Globals, function-local statics, and singletons are shared state whether or not you meant
  them to be, and they are what makes a component impossible to parallelize later. `std::shared_ptr` is in the same
  family - it is a licence for two pieces of code to touch the same object.
- **Prefer message passing to shared memory.** A queue with values moved through it needs one lock, in one place, that
  you can reason about. A graph of objects protected by "whichever mutex the author remembered" cannot be reasoned
  about at all.
- **Prefer immutability.** Data that is never written after publication needs no synchronization at all.
- **Return by value from anything reachable by two threads.** Returning `const&` hands out a reference whose referent
  another thread may be mutating; the caller has no way to know.
- **Watch the heap.** Allocation is a shared resource with a global lock underneath it. Allocation-heavy code often
  scales worse than the same code copying values; measure before assuming threads made it faster.

## The rules for what sharing remains

- **Mutex and `mutable` go together (the M&M rule).** A `mutable` member is by presumption shared, so it must be
  guarded by a mutex or be atomic. A member that _is_ a mutex must be `mutable`, so `const` member functions can lock
  it. A `const` member function is a promise of thread-safety to callers, not merely of non-mutation.
- **Never lock by hand.** `std::scoped_lock` (or `lock_guard`/`unique_lock`) always - it is exception-safe, and
  `scoped_lock` takes multiple mutexes deadlock-free via a lock ordering. A bare `.lock()`/`.unlock()` pair is a leak
  waiting for the next `throw` or early `return`.
- **Establish a global lock order** and document it, for any code that ever holds two mutexes.
- **Never call unknown code while holding a lock** - not a callback, not a virtual function, not an allocation you did
  not budget for. That is how lock-order inversions and unbounded hold times get introduced by someone else's commit.
- **Keep critical sections short and free of I/O.**
- **`std::condition_variable` is always used with a predicate**: `cv.wait(lock, []{ return ready; })`. The
  predicate-free overload is a spurious-wakeup bug. Set the state under the mutex before notifying.
- **Prefer `std::jthread` (C++20).** It joins in its destructor and carries a `std::stop_token`, which removes the two
  most common `std::thread` bugs: forgetting to join and having no way to cancel. Pass the token through and check
  `stop_requested()` in the loop.
- **`std::atomic` is for single variables, not for invariants across two of them.** Default to
  `memory_order_seq_cst`; use a relaxed ordering only with a written justification and a TSan run. Hand-rolled
  lock-free structures are almost never worth it - reach for a reviewed library first.
- **`std::async` is a trap in disguise:** the returned future's destructor blocks for `std::launch::async`, and the
  policy is implementation-chosen if you do not pass one. If you want a thread, say `jthread`; if you want a pool, use
  a pool.
- **Static local initialization is thread-safe (C++11 magic statics); ordinary static _destruction_ order is not**,
  particularly across shared libraries. Do not rely on it.
- **`const` on a standard-library object means safe for concurrent reads only.** Two threads reading the same
  `std::vector` is fine; one writing while another reads is a race even if the reader holds a `const&`.
- Remember `std::vector<bool>` and bitfields: adjacent elements share a word, so "different elements" is not
  automatically "different memory locations".

## Verification is not optional

A data race is undefined behaviour, so testing without instrumentation proves nothing - the race that never fires on
your laptop fires under a different scheduler.

1. **ThreadSanitizer.** Build a dedicated TSan configuration (`-fsanitize=thread`, `-O1 -g`, no ASan in the same
   binary) and run the full suite under it in CI. Treat any TSan report as a build failure.
2. **Stress the schedule.** Run concurrency tests many times, on a machine under load, with more threads than cores.
3. **Enable the hardened/checked standard library** (`-D_GLIBCXX_ASSERTIONS`, `_LIBCPP_HARDENING_MODE`) in test
   builds.
4. **Deadlocks:** reproduce, then attach a debugger and dump all thread stacks (`thread apply all bt`). The cycle is
   visible in the stacks; guessing at it is not.
5. **Measure the speedup.** If the threaded version is not measurably faster than the serial one on realistic data,
   delete the threads - you have bought risk for nothing. Consider parallel algorithm execution policies
   (`std::execution::par`) before hand-rolling anything.

## Reviewing threaded code

Ask, for each piece of mutable state the change touches: which mutex guards it, is that documented next to the
member, and does every access path take it? A member whose answer is "it's only touched from one thread" needs that
assertion written down - ideally as an assert - because the next author will not infer it.

## Sources

Builds on the "Considering Threadability" guidance in Jason Turner's
[C++ Best Practices](https://github.com/cpp-best-practices/cppbestpractices) (CC BY-NC 4.0 - referenced, not
reproduced), Herb Sutter's writing on `const` and the M&M rule, and the concurrency section of the
[C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-concurrency). See also
[C++ Weekly](https://github.com/lefticus/cpp_weekly). Related skills: `cpp-best-practices`, `cpp-review`.
