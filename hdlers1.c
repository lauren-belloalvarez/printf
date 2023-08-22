#include "main.h"

/**
 * print_char - prints char
 * @items: the character to print
 *
 * Return: Number of items printed
 */
int print_char(va_list items)
{
	char c = va_arg(items, int);

	return (write(1, &c, 1));
}

/**
 * print_str - prints str
 * @items: the str to print
 *
 * Return: Number of items printed
 */
int print_str(va_list items)
{
	return (_puts(va_arg(items, char *)));
}

/**
 * print_percent - prints percent sign
 * @items: the character to print
 *
 * Return: Number of items printed
 */
int print_percent(va_list items)
{
	(void)items;

	return (write(1, "%", 1));
}

/**
 * helper_print_count - helps print ints and returns
 * number of ints printed
 * @n: int
 *
 * Return: Number of ints printed
 */
int helper_print_count(int n)
{
	int counter = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		counter++;
		num = -n;
	} else
	{
		num = n;
	}

	if (num / 10)
	{
		counter += helper_print_count(num / 10);
	}
	_putchar((num % 10) + '0');
	counter++;
	return (counter);
}

/**
 * print_int - prints ints
 * @items: the int to print
 *
 * Return: Number of items printed
 */
int print_int(va_list items)
{
	int num = va_arg(items, int);
	int count_int = helper_print_count(num);

	return (count_int);
}
