#include "main.h"

/**
 * is_string - checks string
 *
 * @arg: arguments
 *
 * Return: integer
 */

int is_string(va_list arg)
{
	int n;
	const char *c;

	c = va_arg(arg, const char*);
	if (c == NULL)
		c = "(null)";
	for (n = 0; c[n] != '\0'; n++)
		_putchar(c[n]);
	return (n);
}
