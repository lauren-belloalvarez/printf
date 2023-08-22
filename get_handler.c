#include "main.h"

/**
 * get_handler - finds specifier and relavent conversion function
 *
 * @spec: specifier
 *
 * Return: formatted item
 */

int (*get_handler(char spec))(va_list)
{
	unsigned long int i;

	fmt_t arr[] = {
	{'c', print_char},
	{'s', print_str},
	{'%', print_percent},
	{'i', print_int},
	{'d', print_int},
	{0, NULL}
	};

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (arr[i].spec == spec)
			return (arr[i].hdler);
	}
	return (NULL); /*if spec not found*/
}
