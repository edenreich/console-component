# AGENTS.md — Contributor Guide

This guide helps AI agents and human contributors work with the
`edenreich/console-component` repository. It covers project layout,
build/test commands, coding style, and contribution conventions.

---

## Project Structure

```
.
├── AGENTS.md                  # This file — contributor guide for agents
├── CLAUDE.md -> AGENTS.md     # Symlink for Claude Code compatibility
├── .githooks/
│   └── pre-commit             # Pre-commit hook (typecheck + tests)
├── .clang-format              # WebKit-based C++ formatting rules
├── .gitignore
├── CMakeLists.txt             # Root CMake — delegates to src/ and tests/
├── CHANGELOG.md               # Release notes (Keep a Changelog style)
├── LICENSE
├── README.md
├── cmake/
│   └── CPM.cmake              # CPM dependency manager
├── src/
│   ├── CMakeLists.txt         # Library build — static lib `console`
│   ├── application.cpp
│   ├── input.cpp
│   ├── output.cpp
│   ├── progress_bar.cpp
│   └── include/console/
│       ├── application.h
│       ├── input.h
│       ├── output.h
│       ├── progress_bar.h
│       ├── interfaces/        # Abstract interfaces (CommandInterface, etc.)
│       └── types/             # Type aliases, enums (ExitCode, Colors, etc.)
├── tests/
│   ├── CMakeLists.txt         # Test build — links gtest + console
│   ├── main.cpp               # Google Test entry point
│   └── unit/
│       ├── application_test.cpp
│       ├── input_test.cpp
│       ├── output_test.cpp
│       └── commands/          # Test command stubs (greetings/, todo/)
├── examples/
│   ├── http/                  # Example: HTTP client using the library
│   └── todo/                  # Example: Todo-list CLI app
└── .github/workflows/
    ├── build.yml              # CI: build + test on ubuntu/macos/windows
    ├── lint.yml               # CI: clang-format-18 check
    └── tasks.yml              # Agent workflow dispatch
```

---

## Build & Test

### Prerequisites

- **CMake** ≥ 3.12
- **C++17** compiler (GCC 7+, Clang 5+, MSVC 2017+)
- **make** (or Ninja)

### Configure

```sh
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
```

Tests are enabled by default (`-DWITH_TESTS=ON`). To disable:

```sh
cmake .. -DWITH_TESTS=OFF
```

### Build

```sh
cd build
cmake --build . --target install --config Release
```

The built library and headers are installed to `build/dist/`.

### Run Tests

```sh
./build/bin/tests
```

### Lint (clang-format)

```sh
find . -iname '*.cpp' -o -iname '*.h' | grep -v build | xargs clang-format-18 -n
```

To auto-format in-place, replace `-n` with `-i`.

### Full CI Pipeline (local)

```sh
cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build . --target install --config Release && ../build/bin/tests
```

---

## Coding Style

- **Language**: C++17 (`CMAKE_CXX_STANDARD 17`)
- **Formatting**: WebKit-based via `.clang-format` (4-space indent, 150-char column limit, All namespace indentation)
- **Include guards**: `#ifndef` / `#define` / `#endif` style (uppercase, underscored)
- **Comments**: Doxygen-style (`/** @param ... @return ... */`)
- **Naming**:
  - Classes: PascalCase (`Application`, `CommandInterface`)
  - Methods: camelCase (`setApplicationName`, `getDescription`)
  - Member variables: `m_` prefix (`m_name`, `m_commands`)
  - Namespaces: PascalCase (`Console::`, `Console::Interfaces`, `Console::Types`)
- **No external runtime dependencies** — the library is statically linked and keeps deps minimal
- **SortIncludes**: `false` (includes are not auto-sorted by clang-format)

---

## Commit Conventions

Use **Conventional Commits**:

```
<type>(<scope>): <description>
```

| Type       | Usage                                      |
|------------|--------------------------------------------|
| `feat`     | New feature or command                      |
| `fix`      | Bug fix                                    |
| `chore`    | Tooling, CI, build, or repo maintenance    |
| `docs`     | Documentation changes                       |
| `style`    | Formatting, clang-format changes            |
| `refactor` | Code restructuring without behavior change  |
| `test`     | Adding or updating tests                    |

**Scope** examples: `core`, `input`, `output`, `progress-bar`, `ci`, `docs`.

**Examples:**

```
feat(core): add command suggestion on typo
fix(input): handle empty option values correctly
chore(ci): update cmake version in build workflow
docs(readme): add install instructions for vscode extension
```

---

## Pull Request Conventions

1. **Branch naming**: `feature/<short-description>` or `fix/<short-description>`.
2. **PR title**: Same as the commit message — `type(scope): description`.
3. **PR description**: Include a **Summary** (2–4 sentences) and a **Changes** bullet list.
4. **CI must pass** before review — the build workflow runs on ubuntu, macOS, and Windows.
5. **Do not merge your own PR** — a human maintainer reviews and merges.
6. **Keep PRs focused** — one logical change per PR.

---

## Pre-commit Hook

A `.githooks/pre-commit` script is provided. It runs the project's
typecheck (build) and tests before each commit. The hook is **inert**
until you activate it:

```sh
git config core.hooksPath .githooks
```

Run this once per clone. After that, `git commit` will automatically
build and test your changes. If the build or tests fail, the commit is
aborted.

---

## Agent Workflows

This repository supports agent-driven development via
`.github/workflows/tasks.yml`. Agents are dispatched on:

- `workflow_dispatch` (manual trigger with a prompt)
- `issue` opened or edited
- `issue_comment` created
- `pull_request_review_comment` created

Agents use the `inference-gateway/infer-action` action and are
configured with the `@opentask` trigger phrase.
