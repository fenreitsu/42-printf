*This project was created as part of the 42 curriculum by [reiascan]*

# ft_printf

## Description

`ft_printf` is an individual project from the 42 curriculum whose goal is to recreate the behavior of the `printf` function from the C standard library. The function must interpret a format string, consume the corresponding variadic arguments through `va_list`, and write the result to standard output, returning the total number of characters printed.

Implementing `ft_printf` helped me gain an in-depth understanding of variadic functions (`stdarg.h`) and recursion applied to number conversion in different bases.

---

## Supported conversions

The goal of this project is to replicate the behavior of printf under the specifiers proposed to us by the 42 school. The other specifiers of the original `printf` function are not included, only those in the following list.

| Specifier | Argument | Description |
| :---: | :--- | :--- |
| `%c` | `int` | Prints a single character. |
| `%s` | `char *` | Prints a string; if it is `NULL`, prints `(null)`. |
| `%p` | `void *` | Prints the address in hexadecimal with the `0x` prefix; if it is `NULL`, prints `(nil)`. |
| `%d` | `int` | Prints a signed decimal integer. |
| `%i` | `int` | Prints a signed decimal integer. |
| `%u` | `unsigned int` | Prints an unsigned decimal integer. |
| `%x` | `unsigned int` | Prints an integer in hexadecimal (lowercase). |
| `%X` | `unsigned int` | Prints an integer in hexadecimal (uppercase). |
| `%%` | — | Prints the `%` character. |

This project covers only the **mandatory part** of the subject: it does not implement the bonus flags.

---

## General description of the library and function descriptions

### 1. Program core

* `ft_printf` – Iterates through the format string character by character, initializes and closes the `va_list`, and delegates each conversion to `print_evaluator`. It accumulates and returns the total number of characters written. If the format is `NULL`, it returns `-1`.
* `print_evaluator` – Identifies the conversion specifier and calls the corresponding helper function, extracting the argument with `va_arg`.
* `ft_printf.h` – Single header of the library: declares the prototypes and the required headers (`unistd.h`, `stdlib.h`, `stdarg.h`).

### 2. Helper functions

* `print_char` – Writes a single character to the output descriptor.
* `print_str` – Iterates through and prints a string, handling `NULL` and returning the number of characters.
* `print_digit` – Converts and writes a number in the specified base (10 or 16), in lowercase or uppercase, through recursion. It handles the negative sign of `%d`/`%i`.
* `print_mem_dir` – Prints a memory address with the `0x` prefix, or `(nil)` if the pointer is null.

### 3. Project structure

| File | Contents |
| :--- | :--- |
| `ft_printf.c` | Main loop and `va_list` management. |
| `print_evaluator.c` | Specifier dispatcher. |
| `print_char.c` | `%c` conversion. |
| `print_str.c` | `%s` conversion. |
| `print_digit.c` | `%d`, `%i`, `%u`, `%x`, and `%X` conversions. |
| `print_mem_dir.c` | `%p` conversion. |
| `ft_printf.h` | Prototypes and headers. |
| `Makefile` | Compilation rules and library creation. |

---

## Instructions

### Compilation

The project uses a `Makefile` that compiles all source files with `cc` and the `-Wall -Wextra -Werror` flags, and generates the static library `libftprintf.a` using `ar`.

1. **Compile the library:**

   ~~~bash
   make
   ~~~

   Compiles all `.c` files listed in `SRC` and generates the static library `libftprintf.a`.

2. **Clean the object files:**

   ~~~bash
   make clean
   ~~~

   Removes all object files (`.o`) generated during compilation.

3. **Clean the object files and `libftprintf.a`:**

   ~~~bash
   make fclean
   ~~~

   Removes both the object files and the static library.

4. **Recompile everything from scratch:**

   ~~~bash
   make re
   ~~~

   Runs `fclean` and then `all`, recompiling the entire project.

### Integration and execution

To use `libftprintf.a`:

1. Include the header in your `*.c` file:

   ~~~c
   #include "ft_printf.h"
   ~~~

2. Compile by linking the library:

   ~~~bash
   cc -Wall -Wextra -Werror main.c libftprintf.a
   ~~~

   - `-Wall` enables the important warnings.
   - `-Wextra` enables additional warnings.
   - `-Werror` turns warnings into errors.

   You can also link it by name, telling the linker where to search:

   ~~~bash
   cc -Wall -Wextra -Werror main.c -L. -lftprintf
   ~~~

   - `-L.` tells the linker to search for libraries in the current directory.
   - `-lftprintf` tells it to link against `libftprintf.a` (the `lib` prefix and the `.a` extension are omitted).

   In both cases, the library must be placed **after** the files that use it.

### Usage example

~~~c
#include "ft_printf.h"

int	main(void)
{
	int	n;

	n = 42;
	ft_printf("Hello %s, you are %d years old\n", "Pepito", 42);
	ft_printf("hex: %x | HEX: %X | ptr: %p | %%\n",
		255, 255, (void *)&n);
	return (0);
}
~~~

Output:

~~~text
Hello Pepito, you are 42 years old
hex: ff | HEX: FF | ptr: 0x... | %
~~~

---

## Behavior and notes

* `ft_printf` returns the total number of bytes written, just like `printf`.
* `%s` with `NULL` prints `(null)` and `%p` with `NULL` prints `(nil)` (glibc convention on Linux).
* `%d` with `INT_MIN` and `%u`/`%x`/`%X` with `UINT_MAX` are handled without overflow on 64-bit platforms.
* `%c` with the `\0` character writes the null byte and counts it as a character.
* The `write` function is the only output function used.

---

## Resources

### References and documentation

* **42 subject PDF** – Contains the specific project rules, the exact prototypes, the norm requirements, and the evaluation criteria.
* **https://es.cppreference.com/c/variadic** – Used to review concepts about variadic functions and arguments; it helped me a lot to understand and visualize what was required for this project.
* **https://es.cppreference.com/c/io/fprintf** – Used to review the printf function and try to mimic it in everything required as faithfully as possible.
* **The Linux man (manual)** – Consultation of system commands and the prototypes and behaviors of standard `libc` functions (for example, `man write`, `man printf`), and also consultation of the man pages for `va_start`, `va_arg`, `va_list`, `va_end`.

### Testing tools

* **My own tests** – My tests, although simple, were what helped me pose most of the problems and/or figure out how to approach my functions.
* **https://pythontutor.com/c.html** – Step-by-step visualization tool for C code. It was used to identify bugs, understand the execution flow, and debug pointer handling and recursion.
* **[francinette-image](https://github.com/WaRtr0/francinette-image)** – This tool from the 42 community was used to test my project.

### About the use of AI

* AI was used to create, format, and structure this `README.md` file in accordance with the requirements stated in the subject of this 42 project.
