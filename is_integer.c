#include "main.h"

/**
 * is_integer - prints number of args
 *
 * @arg: arguments
 *
 * Return: returns number
 */

int is_integer(va_list arg)
{
	int a, b;

	a = number(arg);
	return (a);
	for (b = 0; a[b] != '\0'; b++)
		_putchar(a[b]);
	return (b);
}
