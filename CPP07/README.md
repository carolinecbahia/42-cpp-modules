# C++ Module 07: C++ Templates

*This project has been created as part of the 42 curriculum.*

[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)]()
[![Standard](https://img.shields.io/badge/standard-C%2B%2B98-blue.svg)]()
[![Status](https://img.shields.io/badge/status-Not%20started-lightgrey.svg)]()

## Description

Module 07 focuses on generic programming with function templates and class templates. The exercises build on the earlier modules while adhering to the C++98 standard.

**Key Topics:**
- Function templates
- Class templates
- Instantiation
- Const correctness
- Deep copy

**Reference subject:** Module 07, version 10.1 (supplied PDF).

## Technical Requirements

| Requirement | Details |
|------------|---------|
| **Language** | C++98 standard |
| **Compiler** | c++ with flags `-Wall -Wextra -Werror -std=c++98` |
| **Build System** | One Makefile per exercise |
| **Memory Management** | No memory leaks allowed |
| **Code Style** | Clean, readable C++ code; self-sufficient headers and include guards |

## Compilation

```bash
# Compile an exercise (repeat for each exXX directory)
cd CPP07/ex00
make

# Clean object files
make clean

# Full cleanup
make fclean

# Rebuild
make re
```

## Project Structure

```text
CPP07/
├── ex00/                    # Start with a few functions
├── ex01/                    # Iter
├── ex02/                    # Array
└── README.md
```

Each exercise contains its own Makefile, demonstration program, and required source/header files. This is the intended layout; implementation files are not included with this README.

## Exercises Overview

### Exercise 00: Start with a few functions

Implement generic `swap()`, `min()`, and `max()`. Keep the argument type consistent and return the second argument when the values compare equal for min and max.

### Exercise 01: Iter

Implement `iter(array, length, function)` to apply a callable to each array element. Support different element types and respect const correctness, including read-only arrays.

### Exercise 02: Array

Implement `Array<T>` with an empty constructor, sized construction, deep-copy construction and assignment, checked `operator[]`, and `size()`. Invalid indexing must throw an exception; copies must own independent storage.

## Subject Requirements to Check

- Ex00: submit `Makefile`, `main.cpp`, and `whatever.h` or `whatever.hpp`. Define the templates in the header.
- `swap` exchanges two values and returns nothing. `min` and `max` return the second argument when both compare equal. Arguments must have the same type and support the required comparisons.
- Ex01: submit `Makefile`, `main.cpp`, and `iter.h` or `iter.hpp`. `iter` returns nothing and takes the array address, its length passed as a const value, and a function applied to every element.
- Support any array type and instantiated function templates as callbacks. Callbacks may take const or non-const references; preserve element constness.
- Ex02: submit `Makefile`, `main.cpp`, and `Array.h` or `Array.hpp`; `Array.tpp` is optional.
- `Array<T>()` creates an empty array. Construction from `unsigned int n` creates n default-initialized elements, following the subject's `new int()` initialization example.
- Allocate using `new[]`; preventive allocation and access to unallocated memory are forbidden.
- Copy construction and assignment must make independent copies. `operator[]` must throw an exception catchable as `std::exception` for invalid indexes.
- `size()` takes no parameters and must not modify the instance.
- The attached `main.cpp` is an additional Array test with 750 elements, copying, and invalid indexes. It does not replace your own tests.

## Key Concepts Covered

| Concept | Purpose |
|---------|---------|
| **Function templates** | Reuse an operation across compatible types |
| **Class templates** | Parameterize storage by element type |
| **Instantiation** | Generate concrete code at compile time |
| **Const correctness** | Preserve read-only access contracts |
| **Deep copy** | Give each array independent ownership |

## Important Rules

✅ **Allowed:**
- C++98 features permitted by the exercise
- Standard streams and strings
- Required casts, templates, or STL facilities as appropriate to this module

❌ **Forbidden:**
- C++11 and newer features
- Boost and other external libraries
- C-style `printf()`, `malloc()`, `calloc()`, `realloc()`, and `free()`
- `using namespace` directives and `friend`, unless explicitly permitted by the subject

Template definitions must be visible at instantiation, typically in headers or included .tpp files. STL containers and algorithms remain restricted before Module 08.

## Execution Examples

```bash
# Run from the corresponding exercise directory, after building
./templates
```

Executable names and printed output depend on your Makefiles and demonstration programs.

## Testing

Test swap, min, and max with numbers and strings, including equal values. Test iter with mutable and const arrays. Test empty arrays, independent copies, assignment, self-assignment, valid indexes, and indexes outside the array.

Use memory-checking tools where applicable. The scenarios above are a test plan, not a record of completed tests.

## Learning Outcomes

After completing this module, you should be able to:
- Function templates
- Class templates
- Instantiation
- Const correctness
- Deep copy
- Explain implementation decisions and exercise-specific edge cases
- Relate the new concepts to classes, ownership, inheritance, and polymorphism from previous modules

## Compilation Flags Explained

| Flag | Purpose |
|------|---------|
| `-Wall` | Enable common compiler warnings |
| `-Wextra` | Enable additional warnings |
| `-Werror` | Treat warnings as errors |
| `-std=c++98` | Enforce C++98 compliance |

## Common Issues

**Issue:** Undefined references to template functions
- **Solution:** Make template definitions visible from the translation unit using them.

**Issue:** Two arrays share the same allocation
- **Solution:** Implement deep-copy construction and assignment.

**Issue:** Const arrays fail to compile with iter
- **Solution:** Match the callable parameter to the constness of the elements.

## Resources

- The supplied Module 07 subject: exercise requirements and restrictions
- [cppreference](https://en.cppreference.com/w/): language and standard library reference (check C++98 availability)
- Previous modules: object lifetime, copying, inheritance, and polymorphism

## Evaluation Criteria

- [ ] All exercises compile without warnings or errors
- [ ] Required interfaces and behavior match the subject
- [ ] Valid, invalid, and boundary cases are tested
- [ ] No memory leaks or invalid memory access
- [ ] Code follows C++98 and module-specific restrictions
- [ ] Required Orthodox Canonical Form and explicit exercise exemptions are respected
- [ ] Makefiles provide the required targets and do not relink
- [ ] Implementation choices can be explained during peer evaluation

---

**Status:** Not started  
**Last Updated:** November 1, 2026
