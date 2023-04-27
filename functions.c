#include "main.h"

/**
 * print_char - Prints a character.
 * @types: The list of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - Prints a string.
 * @types: The list a of arguments.
 * @buffer: Buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, z;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent - Prints a percent sign.
 * @types: The lists of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print integer.
 * @types: The lists of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	int is_negative = 0;
	long int c = va_arg(types, long int);
	unsigned long int num1;

	c = convert_size_number(c, size);

	if (c == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num1 = (unsigned long int)c;

	if (c < 0)
	{
		num1 = (unsigned long int)((-1) * c);
		is_negative = 1;
	}

	while (num1 > 0)
	{
		buffer[z--] = (num1 % 10) + '0';
		num1 /= 10;
	}

	z++;

	return (write_number(is_negative, z, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number.
 * @types: The lists of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The numbers of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int a, b, c, sum;
	unsigned int d[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(types, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	d[0] = a / b;
	for (c = 1; c < 32; c++)
	{
		b /= 2;
		d[c] = (a / b) % 2;
	}
	for (c = 0, sum = 0, count = 0; c < 32; c++)
	{
		sum += d[c];
		if (sum || c == 31)
		{
			char x = '0' + d[c];

			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
