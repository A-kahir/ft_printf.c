# ft_printf
Because ft_putnbr() and ft_putstr() aren’t enough

## 📋 Project Overview

**ft_printf** is a custom implementation of the C standard library function `printf`. This project, part of the 42 School curriculum, aims to replicate the behavior of `printf`, focusing on formatted output with precise memory and performance management. 

By working on this project, I enhanced my understanding of:
- Variadic functions (`stdarg.h`).
- String manipulation and formatting.
- Error handling and edge case management.

---

## 🚀 Features

- Supports the following format specifiers:
  - `%c` : Character.
  - `%s` : String.
  - `%p` : Pointer address.
  - `%d`/`%i` : Signed decimal integers.
  - `%u` : Unsigned decimal integers.
  - `%x`/`%X` : Hexadecimal (lowercase/uppercase).
- Handles width, precision, and flags (`-`, `0`, `.`).
- Compatible with various edge cases for robust performance.

---

## 🛠️ Usage

To use **ft_printf**, clone the repository and compile the project using the provided `Makefile`:

```bash
git clone https://github.com/A-kahir/ft_printf.git
cd ft_printf
make
