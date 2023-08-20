#include "main.h"
/**
 * p_decimal - a function that prints a decimal
 * @d: the decimal number to be printed
 * Return: returns a number indicating the size
*/
int p_decimal(va_list d)
{
	int length, p, j, dgt, n, cn, num;

	cn = 0;
	length = 0;
	p = 1;
	n = va_arg(d, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			cn++;
		}
		num = n;
		dgt = n / p;
		while (num != 0)
		{
			num /= 10;
			length++;
		}
		for (j = 1; j <= length - 1; j++)
		{
			p *= 10;
		}
		for (j = 1; j <= length; j++)
		{
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
