#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @f: A printed argument with formatted string.
 * @list: Lists of arguments to be printed.
 * @x: index
 * @buffer: Buffer array to handle print.
 * @flags: Flags
 * @width: Width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: A 1 or 2;
 */
int handle_print(const char *f, int *x, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int i, unknow_len = 0, printed_ch = -1;
f1 f_types[] = {
{'c', print_ch}, {'s', print_str}, {'%', print_pct},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hex},
{'X', print_hex_upper}, {'p', print_p}, {'S', print_non_printable},
{'r', print_rev}, {'R', print_rot13string}, {'\0', NULL}
};
for (i = 0; f_types[i].f != '\0'; i++)
if (f[*x] == f_types[i].f)
return (f_types[i].fn(list, buffer, flags, width, precision, size));

if (f_types[i].f == '\0')
{
if (f[*x] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (f[*x - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*x);
while (f[*x] != ' ' && f[*x] != '%')
--(*x);
if (f[*x] == ' ')
--(*x);
return (1);
}
unknow_len += write(1, &f[*x], 1);
return (unknow_len);
}
return (printed_ch);
}
