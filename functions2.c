#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable.
 * @types: The lists of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: The lists of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[z] != '\0')
	{
		if (is_printable(str[z]))
			buffer[z + offset] = str[z];
		else
			offset += append_hexa_code(str[z], buffer, z + offset);

		z++;
	}

	buffer[z + offset] = '\0';

	return (write(1, buffer, z + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @types: The lists of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int z, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (z = 0; str[z]; z++)
		;

	for (z = z - 1; z >= 0; z--)
	{
		char x = str[z];

		write(1, &x, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Print a string in rot13.
 * @types: The lists of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char s;
	char *str;
	unsigned int n, m;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (n = 0; str[n]; n++)
	{
		for (m = 0; in[m]; m++)
		{
			if (in[m] == str[n])
			{
				s = out[m];
				write(1, &s, 1);
				count++;
				break;
			}
		}
		if (!in[m])
		{
			s = str[n];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
