# C++ Module 05: Repetition and Exceptions

*This project has been created as part of the 42 curriculum.*

[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)]()
[![Standard](https://img.shields.io/badge/standard-C%2B%2B98-blue.svg)]()
[![Status](https://img.shields.io/badge/status-Not%20started-lightgrey.svg)]()

## Description

Module 05 focuses on exception handling and object collaboration through a bureaucratic system. The exercises build on the earlier modules while adhering to the C++98 standard.

**Key Topics:**
- Exceptions
- Class invariants
- Abstract classes
- Runtime polymorphism
- Factory pattern

**Reference subject:** Module 05, version 11.1 (supplied PDF).

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
cd CPP05/ex00
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
CPP05/
├── ex00/                    # Mommy, when I grow up, I want to be a bureaucrat!
├── ex01/                    # Form up, maggots!
├── ex02/                    # No, you need form 28B, not 28C...
├── ex03/                    # At least this beats coffee-making
└── README.md
```

Each exercise contains its own Makefile, demonstration program, and required source/header files. This is the intended layout; implementation files are not included with this README.

## Exercises Overview

### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

Implement `Bureaucrat` with a constant name and a grade from 1 (highest) to 150 (lowest). Validate construction and grade changes with `GradeTooHighException` and `GradeTooLowException`, and overload `operator<<`.

### Exercise 01: Form up, maggots!

Implement `Form` with a constant name, signing grade, execution grade, and a signature flag. A form starts unsigned. Implement `beSigned()` and `Bureaucrat::signForm()` to handle signing permissions and report success or failure.

### Exercise 02: No, you need form 28B, not 28C...

Turn the base into abstract `AForm` and add `ShrubberyCreationForm` (sign 145 / execute 137), `RobotomyRequestForm` (72 / 45), and `PresidentialPardonForm` (25 / 5). Execution requires a signature and sufficient authority. Shrubbery writes trees to `<target>_shrubbery`; robotomy succeeds with 50% probability; pardon names Zaphod Beeblebrox.

### Exercise 03: At least this beats coffee-making

Implement `Intern::makeForm()` returning an `AForm*` for `shrubbery creation`, `robotomy request`, or `presidential pardon`. Report unknown names and ensure dynamically allocated forms are released.

## Subject Requirements to Check

- Exception classes are exempt from the Orthodox Canonical Form; other classes must follow it.
- `Bureaucrat` must expose `getName()` and `getGrade()`. Its insertion operator prints `<name>, bureaucrat grade <grade>.` followed by a newline.
- `Form` attributes are private: constant name, signature flag, constant signing grade, and constant execution grade. Provide getters and an insertion operator; validate both required grades in the range 1–150.
- Implement `Form::beSigned(Bureaucrat const&)` and `Bureaucrat::signForm()` with success/failure messages.
- In ex02, replace `Form` with abstract `AForm`, retaining private attributes. Concrete forms take their target as their constructor parameter.
- Implement `AForm::execute(Bureaucrat const& executor) const` and `Bureaucrat::executeForm(AForm const& form) const`. Check signature and execution grade, and report execution success or failure.
- ShrubberyCreationForm: signing grade 145, execution grade 137; write ASCII trees to `<target>_shrubbery`.
- RobotomyRequestForm: signing grade 72, execution grade 45; drilling noises and 50% robotomy success, reporting success or failure.
- PresidentialPardonForm: signing grade 25, execution grade 5; announce that the target has been pardoned by Zaphod Beeblebrox.
- `Intern` has no name or grade. `makeForm()` accepts form name and target, returns the matching `AForm*`, and reports unknown names. Avoid excessive, unreadable if/else chains. Release allocated forms.

## Key Concepts Covered

| Concept | Purpose |
|---------|---------|
| **Exceptions** | Represent and propagate failures with throw, try, and catch |
| **Class invariants** | Keep grades valid throughout object lifetime |
| **Abstract classes** | Define a shared interface without instantiating the base |
| **Runtime polymorphism** | Execute specialized forms through AForm pointers |
| **Factory pattern** | Centralize form creation in Intern |

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

Keep the STL containers and algorithms restriction for this module. Implement the Orthodox Canonical Form where required and keep non-template implementations in source files.

## Execution Examples

```bash
# Run from the corresponding exercise directory, after building
./bureaucrat
```

Executable names and test scenarios are defined by your Makefiles and main.cpp files.

## Testing

Check grades 0, 1, 150, and 151; promotion and demotion at boundaries; valid and invalid signing; execution without a signature; insufficient execution authority; all factory names and an unknown name. Check generated shrubbery files and free every allocated form.

Use memory-checking tools where applicable. The scenarios above are a test plan, not a record of completed tests.

## Learning Outcomes

After completing this module, you should be able to:
- Exceptions
- Class invariants
- Abstract classes
- Runtime polymorphism
- Factory pattern
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

**Issue:** Exception caught by value
- **Solution:** Catch exceptions by const reference to preserve their dynamic type.

**Issue:** Invalid grade after a failed operation
- **Solution:** Validate the new grade before modifying the object.

**Issue:** Leaks through AForm pointers
- **Solution:** Use a virtual base destructor and delete factory-created forms.

## Resources

- The supplied Module 05 subject: exercise requirements and restrictions
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
