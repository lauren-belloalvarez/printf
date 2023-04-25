#include "main.h"
#include <stdio.h>
/**
 * is_binary - conversion for binary
 *
 * @arg: arguments
 *
 * Return: length of binary string
 */

int is_binary(va_list arg)
{
	unsigned int a;
	char binary[binarylength];
	int x, length;

	a = va_arg(arg, unsigned int);
	length = 0;

	for (x = 0; x < binarylength; x++)
	{
		binary[i] = '\0';
	}
	for (x = 0; a > 0; x++)
	{
		binary[x] = (a % 2 == 0) ? '0' : '1';
		a /= 2;
	}
	length = x;
	for (x = length - 1; x >= 0; x--)
	{
		_putchar(binary[x]);
	}
	return (length);
}
