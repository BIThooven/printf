#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
/**
 * struct c_fmt - a structurer
 * @s: the pointer to specifier
 * @f: pointer to function
*/
typedef struct c_fmt
{
	char *s;
	int(*f)(va_list);
} cd_f;
int _putchar(char a);
int _printf(const char *format, ...);
int p_char(va_list c);
int p_str(va_list s);
int p_int(va_list i);
int p_decimal(va_list d);
#endif
