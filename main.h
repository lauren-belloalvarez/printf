#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
int helper_print_count(int n);
int (*get_handler(char spec))(va_list items);

/*Functions for specifiers*/
int print_char(va_list items);
int print_str(va_list items);
int print_percent(va_list items);
int print_int(va_list items);

/**
 * struct fmt - handles the formats
 * @spec: the specifiers
 * @hdler: function pointers for spec
 *
 * Description: structure for handling
 * specifier formats
 */

typedef struct fmt
{

	char spec;
	int (*hdler)(va_list);
} fmt_t;

#endif /*MAIN_H*/
