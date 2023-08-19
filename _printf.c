#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * print_char - a function that prints a character
 * @types: type of arguments
 * @p_buff: an array of args
 * @flags: for active flags
 * @width: width
 * @precision: precision of specifier
 * @size: the size of the array
 * Return: returns 1
*/
int print_char(va_list types, char p_buff[], int flags, int width, int precision, int size)
{
	char c;

	c = va_arg(types, int);
	p_buff[size] = c;
	write(1, &c, 1;

	return (1);
}
/**
 * print_string - a function that prints a string
 * @types: type of arguments
 * @p_buff: an array of args
 * @flags: for active flags
 * @width: width
 * @precision: precision of specifier
 * @size: the size of the array
 * Return: returns count
*/
int print_string(va_list types, char p_buff[], int flags, int width, int precision, int size)
{
	char *str;
	int i, count;

	str = va_arg(types, char *);
	while (str && str[i])
	{
		p_buff[size] = str[i];
		write(1, &str[i], 1);
		count++;
		i++;
	}

	return (count);
}
/**
 * print_percent - a function that prints %
 * @types: type of arguments
 * @p_buff: an array of args
 * @flags: for active flags
 * @width: width
 * @precision: precision of specifier
 * @size: the size of the array
 * Return: returns 1
*/
int print_percent(va_list types, char p_buff[], int flags, int width, int precision, int size)
{
	(void)types;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	p_buff[size] = '%';
	write(1, "%", 1);

	return (1);
}
/**
*print_buffer - printing the content
*@p_buff: an array of characters
*@buff_ind: a pointer to the buffer to be printed
*@size: size of the buffer
*Return: void returns nothing
*/
void print_buffer(char p_buff[], int *buff_ind, int size)
{
	if (*buff_ind > 0)
	{
		write(1, p_buff, *buff_ind);
		*buff_ind = 0;
	}
}
/**
*_printf - a function to print a buffer
*@format: a format specifier
*Return: returns count
*/
int _printf(const char *format, ...)
{
	int i, count;
	va_list list;
	char p_buff[1024];
	int buff_ind;

	i = 0;
	count = 0;
	buff_ind = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_print(format, &i, list, p_buff, 0, 0, 0, buff_ind);
			print_buffer(p_buff, &buff_ind, sizeof(p_buff));
		}
		else
		{
			if (buff_ind >= sizeof(p_buff))
			{
				print_buffer(p_buff, &buff_ind, sizeof(p_buff));
			}
			p_buff[buff_ind++] = format[i];
			count++;
		}
		i++;
	}

	print_buffer(p_buff, &buff_ind, sizeof(p_buff));
	va_end(list);

	return (count);
}
