#include "main.h"
/**
 * p_char - a function to print a character
 * @c: a list of args
 * Return: returns 1 in case of success
*/
int p_char(va_list c)
{
	unsigned char m;

	m = va_arg(c, int);
	_putchar(m);
	return (1);
}
/**
 * p_perc - printing a percent sign
 * Return: returns 1 in case of success
 */
int p_perc(void)
{
	_putchar('%');
	return (1);
}
