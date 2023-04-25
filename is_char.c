#include "main.h"

/**
 * is_char - checks for char
 *
 * @arg: argument
 *
 * Return: 1 if true
 */

int is_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	_putchar(c);
	return (1);
}
