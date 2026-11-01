# C++ Module 09: STL

*This project has been created as part of the 42 curriculum.*

[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)]()
[![Standard](https://img.shields.io/badge/standard-C%2B%2B98-blue.svg)]()
[![Status](https://img.shields.io/badge/status-Not%20started-lightgrey.svg)]()

## Description

Module 09 focuses on container selection, parsing, expression evaluation, and sorting with the STL. The exercises build on the earlier modules while adhering to the C++98 standard.

**Key Topics:**
- Ordered lookup
- Stacks
- Ford–Johnson sorting
- Container selection
- Timing

**Reference subject:** Module 09, version 3.3 (supplied PDF).

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
cd CPP09/ex00
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
CPP09/
├── ex00/                    # Bitcoin Exchange
├── ex01/                    # Reverse Polish Notation
├── ex02/                    # PmergeMe
└── README.md
```

Each exercise contains its own Makefile, demonstration program, and required source/header files. This is the intended layout; implementation files are not included with this README.

## Exercises Overview

### Exercise 00: Bitcoin Exchange

Implement `btc` to read historical exchange rates and an input file of dates and quantities. Use the exact date when available or the closest earlier date otherwise. Validate dates, values, and file formatting, and handle dates before the first available rate.

### Exercise 01: Reverse Polish Notation

Implement `RPN` to evaluate a quoted postfix expression with a stack. For each operator, pop the right operand and then the left operand. Validate tokens, operand availability, division by zero, and that exactly one result remains.

### Exercise 02: PmergeMe

Implement Ford–Johnson merge-insertion sort with two different containers. Parse positive integer arguments, display the sequence before and after sorting, and report processing time for each container. Be ready to explain pairing, recursive ordering, and the insertion order.

## Subject Requirements to Check

- Use at least one standard container in ex00 and ex01, and at least two different containers in ex02. Containers used for an earlier exercise cannot be reused in later exercises.
- Each Makefile must use c++, compile with `-Wall -Wextra -Werror`, avoid relinking, and provide `$(NAME)`, `all`, `clean`, `fclean`, and `re`. Code must also compile with `-std=c++98`.
- Ex00: executable `btc`; submit `Makefile`, `main.cpp`, and `BitcoinExchange.cpp`/`.hpp`. Load the supplied CSV rate database and accept an input filename as an argument.
- Input rows use `date | value` with Year-Month-Day dates and numeric values between 0 and 1000. Multiply the value by the exact date's rate or the closest earlier available rate. Report invalid input appropriately.
- The attached `cpp_09.tgz` contains `cpp_09/data.csv`, the supplied rate database.
- Ex01: executable `RPN`; submit `Makefile`, `main.cpp`, and `RPN.cpp`/`.hpp`. Accept one postfix expression argument and support `+`, `-`, `/`, and `*`.
- Input numbers are less than 10; intermediate values and results have no such restriction. Brackets and decimal numbers need not be handled. Print the result to standard output and errors to standard error.
- Ex02: executable `PmergeMe`; submit `Makefile`, `main.cpp`, and `PmergeMe.cpp`/`.hpp`. Sort positive integer arguments using Ford–Johnson merge-insertion sort.
- Support at least 3,000 integers, including repeated values. Duplicate values must be handled, not rejected.
- Use at least two different containers. The subject strongly advises a separate algorithm implementation for each container rather than a generic function; this is advice, not a mandatory prohibition of templates.
- Print the input sequence, sorted sequence, and a processing-time line identifying each container. Timing must include sorting and data management; choose precision allowing comparison. Errors go to standard error.

## Key Concepts Covered

| Concept | Purpose |
|---------|---------|
| **Ordered lookup** | Find an exact key or its closest earlier key |
| **Stacks** | Evaluate postfix expressions in operand order |
| **Ford–Johnson sorting** | Combine pairing and insertion to order a sequence |
| **Container selection** | Match storage and access patterns to the problem |
| **Timing** | Compare processing costs using consistent measurements |

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

Use different containers across the exercises, following the supplied subject restriction. A possible allocation is std::map for Bitcoin Exchange, std::stack for RPN, and std::vector plus std::deque for PmergeMe. Implement the required sorting algorithm rather than replacing it with std::sort.

## Execution Examples

```bash
# Run from the corresponding exercise directory, after building
./btc input.txt
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./PmergeMe 3 5 9 7 4
```

Bitcoin Exchange also requires its historical rate database. Timings vary by machine and input.

## Testing

Test Bitcoin Exchange with exact and missing dates, invalid calendar dates, negative and excessive quantities, malformed rows, and missing files. Test RPN with valid expressions, too few or extra operands, invalid tokens, and division by zero. Test PmergeMe with sorted, reversed, odd-length, duplicate-containing, invalid, and large inputs; compare both results with a trusted sorted sequence.

Use memory-checking tools where applicable. The scenarios above are a test plan, not a record of completed tests.

## Learning Outcomes

After completing this module, you should be able to:
- Ordered lookup
- Stacks
- Ford–Johnson sorting
- Container selection
- Timing
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

**Issue:** Wrong RPN subtraction or division
- **Solution:** Preserve operand order: left operator right.

**Issue:** Lookup before the earliest exchange date
- **Solution:** Check the lower-bound result before decrementing an iterator.

**Issue:** PmergeMe output is sorted but the algorithm is wrong
- **Solution:** Verify the Ford–Johnson pairing and insertion process, not just the final sequence.

## Resources

- The supplied Module 09 subject: exercise requirements and restrictions
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
