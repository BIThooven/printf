#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * handle_print - prints an argument based on type
 * @fmt: formatted string where to print args
 * @list list of args
 * @i: i
 * @p_buff: an array of args
 * @flags: calculate the flags
 * @width: teh width
 * @precision: precision specifier
 * @size: the size of the specifier
 * Return: count
*/
int handle_print(const char *fmt, int *i, va_list list,
	char p_buff[], int flags, int width, int precision, int size)
{
	int j, count;
	int fmt_len;

	j = 0;
	count = 0;
	fmt_len = sizeof(format_handler_t) / sizeof(format_handler_t[0]);

	for (j = 0; j < fmt_len; j++)
	{
		if (format_handler_t[j].fmt == fmt[*i])
		{
			count += format_handler_t[j].handler(list, p_buff, flags, width, precision, size);
			break;
		}
	}
	return (count);
}
