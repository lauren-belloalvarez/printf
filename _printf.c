#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

/**
 * _printf - prints inputs of functions
 *
 * @format: character string
 *
 * Return: number of characters printed excluding null byte
 */

int _printf(const char *format, ...)
{
	int print;

	converted specs[] = {
		{"c", is_char},
		{"d", is_integer},
		{"s", is_string},
		{"i", is_integer},
		{"%", is_percent},
	};
	va_list arg;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	print = specifiers(format, specs, arg);
	va_end(arg);
	return (print);
}
