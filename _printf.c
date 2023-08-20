#include "main.h"
/**
  * ffunc - a function that take the format for _printf function
  * @format: format specifier
  * Return: NULL or a pointer to the function;
  */
int (*ffunc(const char *format))(va_list)
{
	unsigned int i = 0;
	cd_f fnd_f[] = {
		{"c", p_char},
		{"s", p_str},
		{"i", p_int},
		{"d", p_decimal},
		{NULL, NULL}
	};

	while (fnd_f[i].s)
	{
		if (fnd_f[i].s[0] == (*format))
			return (fnd_f[i].f);
		i++;
	}
	return (NULL);
}
/**
  * _printf - a function to give an output of a certain format
  * @format: format specifier
  * Return: the number of printed formats;
  */
int _printf(const char *format, ...)
{
	va_list args;
	int (*f)(va_list);
	unsigned int i, count;

	i = 0;
	count = 0;
	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			count++;
			i++;
		}
		if (format[i] == '\0')
		{
			return (count);
		}
		f = ffunc(&format[i + 1]);
		if (f != NULL)
		{
			count += f(args);
			i += 2;
			continue;
		}
		if (!format[i + 1])
		{
			return (-1);
		}
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
		{
			i += 2;
		}
		else
			i++;
	}
	va_end(args);
	return (count);
}
