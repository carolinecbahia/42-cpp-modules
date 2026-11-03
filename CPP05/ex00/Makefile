##
## ccavalca - 42 School - C++ Projects Makefile
## Compiled with C++98 Standard
##

# ============================================================================
# COMPILER & FLAGS
# ============================================================================

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
DEBUG_FLAGS	=	-g3 -DDEBUG
CXXFLAGS_OPT=	-O2 -funroll-loops

# ============================================================================
# DIRECTORIES
# ============================================================================

SRC_DIR		=	./
INC_DIR		=	./
OBJ_DIR		=	obj/

# ============================================================================
# FILES
# ============================================================================

SRC_FILES	=	./Bureaucrat.cpp \
				./Bureaucrat.hpp \
				./main.cpp
OBJ_FILES	=	$(SRC_FILES:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

NAME		=	Bureaucrat

# ============================================================================
# RULES
# ============================================================================

.PHONY: all clean fclean re debug help

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ_FILES)
	@echo "✓ $(NAME) compiled successfully with C++98"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "✓ Compiling $<"

debug: CPPFLAGS += $(DEBUG_FLAGS)
debug: clean all
	@echo "✓ Debug build complete"

release: CPPFLAGS += $(CPPFLAGS_OPT)
release: clean all
	@echo "✓ Release build complete"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "✓ Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "✓ All files cleaned"

re: fclean all

# ============================================================================
# ADDITIONAL RULES
# ============================================================================

run: all
	@./$(NAME)

valgrind: debug
	@valgrind --leak-check=full --show-leak-kinds=all \
		--track-origins=yes ./$(NAME)

# ============================================================================
# HELP
# ============================================================================

help:
	@echo "============================================"
	@echo "  C++ Project Makefile (C++98 Standard)"
	@echo "============================================"
	@echo ""
	@echo "Available targets:"
	@echo "  make all      - Build the project (default)"
	@echo "  make clean    - Remove object files"
	@echo "  make fclean   - Remove all generated files"
	@echo "  make re       - Rebuild everything"
	@echo "  make debug    - Build with debug symbols"
	@echo "  make release  - Build optimized release"
	@echo "  make run      - Build and run the program"
	@echo "  make valgrind - Run with memory leak detection"
	@echo "  make help     - Show this help message"
	@echo ""
	@echo "Compiler: c++"
	@echo "Standard: C++98"
	@echo "Flags: -Wall -Wextra -Werror"
	@echo "============================================"
