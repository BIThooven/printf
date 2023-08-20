#include "main.h"
/**
 * p_int - Print an integer from a va_list
 * @i: va_list containing the integer to print
 *
 * Return: Number of characters printed
 */
int p_int(va_list i)
{
	int length, p, j, dgt, n, cn, num;

	cn = 0;
	length = 0;
	p = 1;
	n = va_arg(i, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			cn++;
		}
		num = n;
		while (num != 0)
		{
			num /= 10;
			length++;
		}
		for (j = 1; j <= length; j++)
		{
			p *= 10;
		}
		for (j = 1; j <= length; j++)
		{
			dgt = n / p;
			if (n < 0)
			{
				_putchar((dgt * -1) + 48);
			}
			else
			{
				_putchar(dgt + '0');
			}
			cn++;
			n -= dgt * p;
			p /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (cn);
}
