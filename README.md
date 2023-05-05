# 42_printf
## Getting Started
This project implements a custom printf function that mimics the behavior of the standard printf function from the C standard library. It supports the following format specifiers:
- %c - Prints a single character
- %s - Prints a string
- %p - Prints a pointer adress
- %d or %i - Prints a signed integer
- %u - Prints an unsigned integer
- %x or %X - Prints an unsigned integer in hexadecimal format
### Makefile
- make or make all - Makes libftprintf.a
- make clean - Deletes all the resulting object files
- make fclean - Deletes libftprintf.a and all the resulting object files
- make re - Deletes everything (object files and libftprintf.a) and rebuilds libftprintf.a
