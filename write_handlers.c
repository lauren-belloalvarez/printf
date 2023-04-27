#include "main.h"

/**
 * handle_write_char - rints a character to a buffer based on
 * the provided parameters.
 * @c: the character to be printed
 * @buffer: the array of characters to which the character will be printed
 * @flags:  a bitmask representing the active flags
 * @width: the width specifier
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: the number of characters printed
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[z++] = c;
	buffer[z] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (z = 0; z < width - 1; z++)
			buffer[BUFF_SIZE - z - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - z - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - z - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints a number to a buffer based on the provided parameters
 * @is_negative: a boolean indicating whether the number is negative or not
 * @ind: the index of the number in the buffer
 * @buffer: the array of characters to which the number will be printed
 * @flags:  a bitmask representing the active flags
 * @width: the width specifier
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: the number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Writes a number to a buffer based on the provided parameters.
 * @ind: the index at which the number starts in the buffer
 * @buffer: the buffer to which the number will be written
 * @flags: a bitmask representing the active flags
 * @width: the width specifier
 * @prec: the precision specifier
 * @length: the length of the number
 * @padd: the character used for padding
 * @extra_c: an extra character to be written before or after the number
 *
 * Return: the number of printed characters
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int z, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (z = 1; z < width - length + 1; z++)
			buffer[z] = padd;
		buffer[z] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], z - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], z - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number to a buffer based
 * on the provided parameters.
 * @is_negative: a boolean indicating whether the number is negative or not
 * @ind: the index of the number in the buffer
 * @buffer: the array of characters to which the number will be written
 * @flags: a bitmask representing the active flags
 * @width: the width specifier
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: the number of characters written
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, z = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (z = 0; z < width - length; z++)
			buffer[z] = padd;

		buffer[z] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], z));
		}
		else
		{
			return (write(1, &buffer[0], z) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Writes a memory address to a buffer based
 * on the provided parameters.
 * @buffer: array of characters to which the memory address will be written
 * @ind: the index at which the memory address starts in the buffer
 * @length: the length of the memory address
 * @width: the width specifier
 * @flags: the flags specifier
 * @padd: the character used for padding
 * @extra_c: an extra char to be written before or after the memory address
 * @padd_start: the index at which padding should start
 *
 * Return: the number of characters written
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int z;

	if (width > length)
	{
		for (z = 3; z < width - length + 3; z++)
			buffer[z] = padd;
		buffer[z] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], z - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], z - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], z - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
