# C++ Module 08: Templated Containers, Iterators and Algorithms

*This project has been created as part of the 42 curriculum.*

[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)]()
[![Standard](https://img.shields.io/badge/standard-C%2B%2B98-blue.svg)]()
[![Status](https://img.shields.io/badge/status-Not%20started-lightgrey.svg)]()

## Description

Module 08 focuses on STL containers, iterators, algorithms, and container adapters. The exercises build on the earlier modules while adhering to the C++98 standard.

**Key Topics:**
- Containers
- Iterators
- STL algorithms
- Container adapters
- Complexity

**Reference subject:** Module 08, version 10.1 (supplied PDF).

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
cd CPP08/ex00
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
CPP08/
├── ex00/                    # Easy find
├── ex01/                    # Span
├── ex02/                    # Mutated abomination
└── README.md
```

Each exercise contains its own Makefile, demonstration program, and required source/header files. This is the intended layout; implementation files are not included with this README.

## Exercises Overview

### Exercise 00: Easy find

Implement `easyfind()` to locate an integer in an integer container, using iterators and an STL search algorithm. Provide a clear failure path when the value is absent.

### Exercise 01: Span

Implement a capacity-limited collection of integers with `addNumber()`, `shortestSpan()`, and `longestSpan()`. Reject additions beyond capacity and span queries with fewer than two values. Support adding a range of values and test large datasets.

### Exercise 02: Mutated abomination

Implement `MutantStack` to expose iteration over the underlying container of `std::stack`, while retaining stack operations. Compare traversal and behavior with a standard iterable container.

## Subject Requirements to Check

- Use STL containers and algorithms wherever appropriate; their use is the purpose of this module.
- Template definitions may be in headers or optional .tpp files; required headers must still be submitted.
- Ex00: `easyfind` searches for the first occurrence of an integer in a container of integers. If absent, throw an exception or return an error value of your choice. Associative containers need not be supported.
- Ex01: `Span` takes an unsigned integer capacity N as its constructor parameter. `addNumber()` throws when capacity is exhausted. `shortestSpan()` and `longestSpan()` throw when fewer than two numbers are stored.
- Test Span with at least 10,000 numbers. Implement a member function adding multiple values in one call using a range of iterators.
- Ex02: `MutantStack` is implemented in terms of `std::stack`, exposes all its member functions, and adds iterators.
- Verify the subject example: begin/end traversal, iterator increment/decrement, and construction of `std::stack<int>` from a MutantStack. Compare output with an iterable container such as `std::list` using corresponding operations.

## Key Concepts Covered

| Concept | Purpose |
|---------|---------|
| **Containers** | Choose storage according to required operations |
| **Iterators** | Traverse container elements through a common interface |
| **STL algorithms** | Reuse generic operations such as std::find and sorting |
| **Container adapters** | Extend access to the container underlying std::stack |
| **Complexity** | Assess cost as dataset size grows |

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

STL containers and algorithms are central to this module and should be used where appropriate. Keep template definitions visible and preserve iterator validity rules.

## Execution Examples

```bash
# Run from the corresponding exercise directory, after building
./span
```

Use the executable names defined in each exercise Makefile.

## Testing

Test easyfind with present, absent, and repeated values. Test Span with zero, one, two, duplicate, negative, and extreme integer values; full capacity; range insertion; and at least 10,000 numbers. Test MutantStack push, pop, top, copying, and iteration.

Use memory-checking tools where applicable. The scenarios above are a test plan, not a record of completed tests.

## Learning Outcomes

After completing this module, you should be able to:
- Containers
- Iterators
- STL algorithms
- Container adapters
- Complexity
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

**Issue:** Span arithmetic overflows
- **Solution:** Promote operands to a sufficiently wide type before subtraction.

**Issue:** Span query has too few elements
- **Solution:** Throw an exception before attempting the calculation.

**Issue:** Iterator becomes invalid
- **Solution:** Check the invalidation rules of the underlying container after modifications.

## Resources

- The supplied Module 08 subject: exercise requirements and restrictions
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
