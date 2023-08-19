#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
 * struct format_handler - Struct for format specifier and handler
 * @fmt: The format specifier
 * @handler: a functions pointer , specifier handler
 */
struct format_handler
{
	char fmt;
	int (*handler)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct format_handler format_handler_t-Typedef struct format_handler
 */
typedef struct format_handler format_handler_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char p_buff[], int flags, int width, int precision, int size);
int print_char(va_list types, char p_buff[],
int flags, int width, int precision, int size);
int print_string(va_list types, char p_buff[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char p_buff[],
int flags, int width, int precision, int size);
void print_buffer(char p_buff[], int *buff_ind, int size);
#endif
