#include "main.h"

/**
 * print_unsigned - Prints an unsigned number.
 * @types: The list of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int num1 = va_arg(types, unsigned long int);

	num1 = convert_size_unsgnd(num1, size);

	if (num1 == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num1 > 0)
	{
		buffer[z--] = (num1 % 10) + '0';
		num1 /= 10;
	}

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: The list of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int z = BUFF_SIZE - 2;
	unsigned long int num1 = va_arg(types, unsigned long int);
	unsigned long int init_num = num1;

	UNUSED(width);

	num1 = convert_size_unsgnd(num1, size);

	if (num1 == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num1 > 0)
	{
		buffer[z--] = (num1 % 8) + '0';
		num1 /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[z--] = '0';

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
  * @types: The list of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: The list of arguments.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper.
 * @types: The lists of arguments.
 * @map_to: The array of values to map the number to.
 * @buffer: The buffer array to handle print.
 * @flags:  The active flags.
 * @flag_ch: The active flags.
 * @width: The width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * @size: The size specification.
 * Return: The number of characters printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int num1 = va_arg(types, unsigned long int);
	unsigned long int init_num = num1;

	UNUSED(width);

	num1 = convert_size_unsgnd(num1, size);

	if (num1 == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num1 > 0)
	{
		buffer[z--] = map_to[num1 % 16];
		num1 /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[z--] = flag_ch;
		buffer[z--] = '0';
	}

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}
