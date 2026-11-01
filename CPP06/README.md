# C++ Module 06: C++ Casts

*This project has been created as part of the 42 curriculum.*

[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)]()
[![Standard](https://img.shields.io/badge/standard-C%2B%2B98-blue.svg)]()
[![Status](https://img.shields.io/badge/status-Not%20started-lightgrey.svg)]()

## Description

Module 06 focuses on explicit type conversion, pointer representation, and runtime type identification. The exercises build on the earlier modules while adhering to the C++98 standard.

**Key Topics:**
- static_cast
- reinterpret_cast
- dynamic_cast
- RTTI
- Numeric limits

**Reference subject:** Module 06, version 8.1 (supplied PDF).

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
cd CPP06/ex00
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
CPP06/
├── ex00/                    # Conversion of scalar types
├── ex01/                    # Serialization
├── ex02/                    # Identify real type
└── README.md
```

Each exercise contains its own Makefile, demonstration program, and required source/header files. This is the intended layout; implementation files are not included with this README.

## Exercises Overview

### Exercise 00: Conversion of scalar types

Implement `ScalarConverter` to display a literal as `char`, `int`, `float`, and `double`. Handle impossible conversions, non-displayable characters, range limits, precision, and special values such as `nan`, `nanf`, `+inf`, `-inf`, `+inff`, and `-inff`.

### Exercise 01: Serialization

Implement `Serializer::serialize(Data*)` and `Serializer::deserialize(uintptr_t)`. Use `reinterpret_cast` to convert a pointer to an integer representation and back. Verify that the reconstructed pointer equals the original; this does not serialize object contents.

### Exercise 02: Identify real type

Implement polymorphic `Base` and derived `A`, `B`, and `C`, plus `generate()`, `identify(Base*)`, and `identify(Base&)`. Use `dynamic_cast` to identify the runtime type without `<typeinfo>`.

## Subject Requirements to Check

- Each exercise must use an appropriate explicit C++ cast; justify the choice during evaluation.
- Ex00: `ScalarConverter` must not be instantiable by users and must expose only one static method, `convert()`, taking the literal as a string.
- Detect the input literal type, convert the string to that type, then explicitly convert to the other three types. Only decimal notation is required except for char inputs. Non-displayable characters are not required as inputs.
- Print char, int, float, and double results in that order. Report impossible/overflowing conversions and non-displayable character results. Handle `nan`, `nanf`, `+inf`, `-inf`, `+inff`, and `-inff`.
- Ex01: `Serializer` must not be instantiable. Its methods are static: `uintptr_t serialize(Data* ptr)` and `Data* deserialize(uintptr_t raw)`.
- Submit a non-empty `Data` structure and verify that deserializing the serialized pointer returns the original pointer.
- Ex02: `Base` has only a public virtual destructor. A, B, and C are empty public derived classes. These four classes are exempt from the Orthodox Canonical Form.
- Implement `Base* generate(void)`, `void identify(Base*)`, and `void identify(Base&)`. Generation randomly chooses A, B, or C; identification prints its actual type.
- Using a pointer inside `identify(Base&)` is forbidden. `std::typeinfo` and inclusion of `<typeinfo>` are forbidden.

## Key Concepts Covered

| Concept | Purpose |
|---------|---------|
| **static_cast** | Perform explicit scalar conversions after validating range |
| **reinterpret_cast** | Convert between pointer and integer representations |
| **dynamic_cast** | Check conversions within a polymorphic hierarchy |
| **RTTI** | Inspect runtime types through a polymorphic base |
| **Numeric limits** | Avoid invalid or out-of-range conversions |

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

STL containers and algorithms remain restricted before Module 08. Exercise 02 forbids `<typeinfo>`; Base must be polymorphic for the required dynamic casts.

## Execution Examples

```bash
# Run from the corresponding exercise directory, after building
./convert "42"
./convert "nan"
```

The conversion executable is shown here; use the executable names selected for the other exercises.

## Testing

Test character, integer, float, and double literals; malformed input; non-displayable characters; integer boundaries; floating-point special values; pointer round trips; and identification of A, B, and C through both pointer and reference interfaces.

Use memory-checking tools where applicable. The scenarios above are a test plan, not a record of completed tests.

## Learning Outcomes

After completing this module, you should be able to:
- static_cast
- reinterpret_cast
- dynamic_cast
- RTTI
- Numeric limits
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

**Issue:** Out-of-range numeric conversion
- **Solution:** Validate bounds before converting to an integral type.

**Issue:** Reference dynamic_cast fails
- **Solution:** Handle std::bad_cast; a failed pointer cast returns a null pointer instead.

**Issue:** Serialized data appears unchanged
- **Solution:** The exercise converts an address, not the contents of Data.

## Resources

- The supplied Module 06 subject: exercise requirements and restrictions
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
