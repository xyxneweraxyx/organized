# Compilation
TARGET := organized
CC := clang
FLAGS := -Wall -Wextra -Wno-implicit-function-declaration -O1

# Sources
SRC := $(shell find . -name '*.c')
LIB := $(shell find . -name '*.a')
OBJ := $(SRC:.c=.o)
HDR := $(shell find . -name '*.h')

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(TARGET)

clean:
	rm -f $(shell find . -name '*.o')
	rm -f $(shell find . -name '*.c~')
	rm -f $(shell find . -name '*.h~')
	rm -f $(shell find . -name '*#*')
	rm -f $(shell find . -name '*.pch')
	rm -f $(shell find . -name '*.out')
	rm -f $(shell find . -name '*~')

fclean: clean
	rm -f $(shell find . -name '$(TARGET)')

re: fclean $(TARGET)

print_src:
	$(info $(SRC))

epiclang_all:
	epiclang $(SRC) $(HDR)

# Tests Criterion
TEST_SRC_FILES := ./lib/debug/my_printf.c \
                  ./lib/str/str_to_int.c \
                  ./lib/str/str_cmp.c \
                  ./lib/str/str_dup.c \
                  ./lib/malloc/error_frees.c \
                  ./src/disp.c \
                  ./src/del.c \
                  ./src/sort.c \
                  ./src/add.c

tests_sort: 
	@$(CC) $(FLAGS) -o test_sort_advanced $(TEST_SRC_FILES) tests_sort_advanced.c -lcriterion && ./test_sort_advanced --verbose