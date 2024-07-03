# ft_printf

This project involves partially replicating the printf function from the C standard library using resources that convert ft_printf into a variadic function. This means it can accept an indeterminate number of parameters.

### Overview

The function prototype is as follows: 

```
int ft_printf(const char *, ...);
```

* Return value: Returns the number of bytes printed.
* Parameters: 
    * Format string: A string containing characters and format specifiers. Format specifiers start with '%' followed by characters that dictate how subsequent arguments should be formatted.
    * Additional arguments: Values to be formatted according to the format specifiers in the format string. The number of these arguments depends on the number of format specifiers in the format string.

This implementation of ft_printf supports the following conversions:

* %c: Prints a character.
* %s: Print a string.
* %p: Prints a pointer address.
* %d: Prints an intger.
* %i: Prints an int.
* %u: Prints an unsigned int.
* %x: Prints an integer in lowercase hexadecimal.
* %X: Prints an integer in uppercase hexadecimal.
* %%: Prints a percent symbol.

### Variadic functions

To utilize the ft_printf function with any number of arguments, you need to use a variadic list, which is defined using the system data type va_list. This facilitates handling through the following functions:

* void va_start(va_list ap, argN): This function initializes the variadic list, preparing it to access the variable arguments starting from argN.
* *type* va_arg(va_list ap, type): It interprets the argument within the va_list as the specified data type type, advancing the pointer to access subsequent arguments.
* void va_end(va_list ap): Marks the end of the variadic argument list, ensuring proper cleanup and signaling that all arguments have been processed.

These functions utilize pointer arithmetic to precisely determine the memory location and size of each variable passed to the function. This ensures that the function can effectively retrieve and process each argument within the variadic list. Knowledge of the argument types beforehand is crucial because it allows the functions to correctly interpret and access each argument's data, maintaining the integrity of the operation and preventing errors that might occur if the type information were incorrect or missing.

### Implementation

The ft_printf function is straightforward: it processes a string character by character, writing each to the standard output. To achieve this, it utilizes a byte counter that increments for each character encountered in the string. When encountering a '%' symbol, it checks the subsequent character to determine the type of variable conversion required. Then, it identifies the corresponding argument from the variadic list.

Depending on the specified conversion type, it applies the appropriate formatting. Here's how each conversion is handled:

* %c: Uses the write() function to output a single character.
* %s: Uses the write() function to output an entire string.
* %p: Casts the argument to unsigned long long and converts it to hexadecimal using ft_itoa_base with base 16.
* %d: Casts the argument to int and converts it to a string using ft_itoa.
* %i: Similar to %d, it casts the argument to int and converts it to a string using ft_itoa.
* %u:  Casts the argument to unsigned int and converts it to a string using ft_itoa.
* %x: Casts the argument to unsigned int and converts it to lowercase hexadecimal using ft_itoa_base_lower with base 16.
* %X: Casts the argument to unsigned int and converts it to uppercase hexadecimal using ft_itoa_base_upper with base 16.
* %%: Uses the write() function to output a percent symbol.

These conversions are straightforward and are implemented accordingly within ft_printf to handle different data types and formatting requirements specified by the format string.
