#ifndef _PRINTF
#define _PRINTF
#include <unistd.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

struct convert
{
	char *sym;
	int (*f) (va_list);
};
typedef struct convert converted;

int _putchar(char c);
int specifiers(const char *format, converted specs[], va_list arg);
int _printf(const char *format, ...);
int number(va_list args);
int un_number(unsigned int n);
int is_char(va_list);
int is_string(va_list arg);
int is_percent(va_list);
int is_integer(va_list);
#endif
