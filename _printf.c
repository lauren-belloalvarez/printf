#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - prints inputs of functions
 *
 * @format: character string
 *
 * Return: number of characters printed excluding null byte at the end of strings
 */

/**
 * buffunc - will print buffer content
 *
 * @buffer: chars array
 * @y: index length
 *
 */

void buffunc(char buffer[], int *y)
{
	if (y > 0)
		write(1, &buffer[0], int *y)
	*y = 0;
}

int _printf(const char *format, ...)
{
	int n, chars = 0, a = 0;
	int y = 0, flag;
	va_list x;
	char buffer[buffersize];

	va_start(x, format);
	for (n = 0; format && format [n] != '\0'; n++)
	{
		if (format == NULL || format[n] == '%' && !format[n + 1])
			return (-1);
		if (format[n] != '%')
		{
			buffer[y++] = format[n];
			if (y == buffersize)
				buffunc(buffer,&y);
			chars++;
		}
		else
		{
			buffunc(buffer, &y);
			flag = get_flags(format, &n);
			n++;
			a = handle_print(format, &n, x, buffer, flag);
			if (a == -1)
				return (-1);
			printed += a;
		}
	}
	buffunc(buffer, &y);
	va_end(x);
	return (printed);
}
