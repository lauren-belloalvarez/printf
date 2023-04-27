#include "main.h"

/**
 * is_printable - Determines whether a given character is printable.
 * @c: the character to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Appends the ASCII code in hexadecimal format to
 * a buffer starting at the specified index.
 * @buffer: the array of characters to which the hexadecimal
 * code will be appended
 * @i: Index at which to start appending.
 * @ascii_code: the ASCII code to be converted to hexadecimal and appended
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
 * is_digit - Determines whether a given character is a digit.
 * @c: the character to be evaluated
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a given number to the specified size.
 * @num: the number to be casted
 * @size: the size to which the number will be casted
 *
 * Return: the casted value of num
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
 * convert_size_unsgnd - Casts a number to the specified unsigned  size
 * @num: the number to be casted
 * @size:  the size to which the number will be casted
 *
 * Return: the casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
