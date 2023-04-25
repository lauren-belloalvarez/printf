#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * specifiers - checks for special characters and inserts string
 *
 * @format: string
 * @specs: list of specifiers to check
 * @arg: list of arguemnts from main function
 *
 * Return: number of chars
 */

int specifiers(const char *format, converted specs[], va_list arg)
{
	int n, i, value, print;

	print = 0;

	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] == '%')
		{
			for (i = 0; specs[i].sym != NULL; i++)
			{
				if (format[n + 1] == specs[i].sym[0])
				{
					value = specs[i].f(arg);
					if (value == -1)
						return (-1);
					print = print + value;
					break;
				}
			}
			if (specs[i].sym == NULL && format[n + 1] != ' ')
			{
				if (format[n + 1] != '\0')
				{
					_putchar(format[n]);
					_putchar(format[n + 1]);
					print = print + 2;
				}
				else
					return (-1);
			}
			n = n + 1;
		}
		else
		{
			_putchar(format[n]);
			print++;
		}
	}
	return (print);
}
