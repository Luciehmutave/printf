#include "main.h"

/**
 * _printable - Evaluates if a char is printable
 * @c: Characters to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int _printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}
/**
 * _digit - Checks if a character is a digit
 * @c: Character to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _digit(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

/**
 * convert_size_number - Number to be cast to a specified size
 * @num: Number to be casted.
 * @size: Size
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);

return ((int)num);
}

/**
 * convert_size_unsigned - Number to be casted to a specified size
 * @num: Number to be casted
 * @size: Size
 *
 * Return: Casted value of num
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
