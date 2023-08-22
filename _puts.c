#include "main.h"

/**
 * _puts - prints string to standard output
 *
 * @str: input string
 *
 * Return: length of string
 */

int _puts(char *str)
{
	int len = 0;

	while (str && str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
