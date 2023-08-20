#include "main.h"
/**
 * p_str - a function to print a string
 * @s: a list of args
 * Return: returns 1 in case of success
*/
int p_str(va_list s)
{
	char *m;
	int  i;

	i = 0;
	m = va_arg(s, char *);

	if (m == NULL)
	{
		m = "(null)";
	}
	while (m[i])
	{
		_putchar(m[i]);
		i++;
	}
	return (i);
}
