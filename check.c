#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * number - numbers to print
 *
 * @arg: arguments
 *
 * Return: number of args
 */

int number(va_list arg)
{
	int a, b, length;
	unsigned int c;

	a = va_arg(arg, int);
	b = 1;
	length = 0;

	if (a < 0)
	{
		length = length + _putchar('-');
		c = a * -1;
	}
	else
		c = a;
	for (; c / b > 9;)
		b *= 10;
	for (; b != 0;)
	{
		length = length + _putchar('0' + c / b);
		b %= c;
		b /= 10;
	}
	return (length);
}

/**
 * un_number - returns length
 *
 * @n: integer
 *
 * Return: length
 */

int un_number(unsigned int n)
{
	int a, length;
	unsigned int b;

	a = 1;
	b = n;
	length = 0;
	if (n == 0)
	{
		length += _putchar('0');
	}
	else
	{
		if ((int)n < 0)
		{
			length += _putchar('-');
			b = -b;
		}
		for (; a <= (int)b / 10; a *= 10)
		{
			for (; a != 0; a /=10)
			{
				length += _putchar('0' + (b / a));
				b %= a;
			}
		}
	}
	return (length);
}
