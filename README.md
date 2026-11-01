# C++ Modules — 42 São Paulo

*This project has been created as part of the 42 curriculum by carolinecbahia.*

![Language](https://img.shields.io/badge/language-C%2B%2B-blue)
![Standard](https://img.shields.io/badge/standard-C%2B%2B98-orange)
![Modules](https://img.shields.io/badge/modules-00–09-blue)
![Progress](https://img.shields.io/badge/completed-5%2F10-brightgreen)
![Status](https://img.shields.io/badge/status-In%20progress-yellow)

## Overview

My C++ learning journey at **42 São Paulo**, covering modules **CPP00 through CPP09**. The modules progress from classes and object lifetime to inheritance, polymorphism, exceptions, casts, templates, and the Standard Template Library (STL).

All projects target **C++98**. CPP00–CPP04 have been passed and are scheduled for review; CPP05–CPP09 are the next implementation stages.

## Modules & Progress

| Module | Main topics | Status | Grade | Documentation |
|--------|-------------|--------|-------|---------------|
| **CPP00** | Namespaces, classes, streams, static members, const | Passed · review pending | 80/100 | [README](CPP00/README.md) |
| **CPP01** | Allocation, references, member pointers, file streams | Passed · review pending | 90/100 | [README](CPP01/README.md) |
| **CPP02** | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | Passed · review pending | 80/100 | [README](CPP02/README.md) |
| **CPP03** | Inheritance, construction and destruction order | Passed · review pending | 80/100 | [README](CPP03/README.md) |
| **CPP04** | Subtype polymorphism, abstract classes, interfaces | Passed · review pending | 80/100 | [README](CPP04/README.md) |
| **CPP05** | Exceptions, invariants, object factories | Not started | — | [README](CPP05/README.md) |
| **CPP06** | Scalar conversion, serialization, runtime type identification | Not started | — | [README](CPP06/README.md) |
| **CPP07** | Function templates, iteration, class templates | Not started | — | [README](CPP07/README.md) |
| **CPP08** | Containers, iterators, STL algorithms, adapters | Not started | — | [README](CPP08/README.md) |
| **CPP09** | Parsing, data structures, sorting, performance | Not started | — | [README](CPP09/README.md) |

## Getting Started

### Prerequisites

- A C++ compiler available as `c++` (GCC or Clang)
- `make`
- Linux, macOS, or a compatible development environment such as WSL2

### Build & Run

Run Make from the individual exercise directory:

```bash
cd CPP00/ex00
make
# Run the executable produced by this Makefile

# Remove object files
make clean

# Remove object files and executable
make fclean

# Rebuild
make re
```

Compile with `-Wall -Wextra -Werror`; code must also compile with `-std=c++98`. Executable names and arguments vary by implementation.

## Development Practices

- Target C++98 and enable compiler warnings.
- Write readable code with clear ownership and object lifetimes.
- Check copying behavior, const correctness, and memory safety.
- Keep headers self-contained and protect them against multiple inclusion.
- Test normal behavior, boundary conditions, and error handling.

## Review & Learning Plan

1. Review CPP00–CPP04, focusing on object lifetime, copying, const correctness, inheritance, and virtual dispatch.
2. Connect those foundations to CPP05: preserve object invariants with exceptions and reuse polymorphism for specialized forms.
3. Study explicit conversions in CPP06, then compile-time generic programming in CPP07.
4. Apply templates through STL containers, iterators, and algorithms in CPP08.
5. Combine parsing, container selection, correctness, and complexity analysis in CPP09.

## Author

[Caroline Bahia](https://github.com/carolinecbahia) · 42 São Paulo

This repository documents my C++ learning journey and implementation progress.

---

**Last updated:** November 1, 2026