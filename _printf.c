#include "main.h"

/**
 * _printf - prints output according to a format
 *
 * @format: character string
 *
 * Return: number of characters printed excluding null
 */

int _printf(const char *format, ...)
{
	int i, counter = 0;
	va_list items;

	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ')
	{
		return (-1);
	}

	va_start(items, format);

	i = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			int (*handler)(va_list) = get_handler(format[i + 1]);

			if (handler)
			{
				counter += handler(items);
			}
			i += 2;
		}
		else
		{
			counter += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(items);
	return (counter);
}
