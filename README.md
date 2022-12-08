# FT_PRINTF
Replicated C Standard library's `printf` function.

# Supported features
- Specifiers

  |Specifiers|Output|Example|
  |:---:|:------|:----:|
  | `d` , `i`| *signed integer*|-42|
  | `u`| *unsigned integer* |42|
   |`o`| *unsigned octal* |42|
   |`x`| *unsigned hexadecimal (lowercase)* |2a|
   |`X`| *unsigned hexadecimal (uppercase)* |2A|
  |`f`| *decimal floating point* |42.42|
  
- Sub-specifiers

   |Flags| Desciption|
   |:--:|------|
   |`-`|Left-justify within the given field width; Right justification is the default|
   |`+`|Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign|
   |`space`|If no sign is going to be written, a blank space is inserted before the value.|
    |`0`|Left-pads the number with zeroes (0) instead of spaces when padding is specified|
    |`#`|Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.|
   
   |Width|Description|
   |:-----:|--------|
   |*(number)*|Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
    |`*`|	The *width* is not specified in the *format* string, but as an additional integer value argument preceding the argument that has to be formatted.|
    
    
    |.precision| Description|
    |:------:|---------|
    |*(number)*|For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.|
    |`*`|The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|
# Examples
``` C
ft_printf("%s", "Hello World!\n");
ft_printf("%d\n", 42);
ft_printf("%o\n", 42);
ft_printf("%x\n", 42);
ft_printf("%X\n", 42);
ft_printf("%f\n", 42.42f);
```
Output:
````
Hello World!
42
52
2a
2A
42.420000
