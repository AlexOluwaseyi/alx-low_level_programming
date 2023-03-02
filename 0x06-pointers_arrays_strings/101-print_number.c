#include "main.h"

/**
 * print_number - prints an integer
 * @n: Negative or positive integer
 */

void print_number(int n)
{
	if (n >= 0 && n <= 9)
		_putchar(n + '0');
	if (n >= 10 && n <= 99)
	{
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	if (n >= 100 && n <= 999)
	{
		_putchar((n / 100) + '0');
		_putchar(((n / 10) % 10) + '0');
		_putchar((n % 10) + '0');
	}
	if (n >= 1000 && n <= 9999)
	{
		_putchar((n / 1000) + '0');
		_putchar(((n / 100) % 10) + '0');
		_putchar(((n / 10) % 10) + '0');
		_putchar((n % 10) + '0');
	}
	if (n < 0 && n >= -99)
	{
		n = -(n);
		_putchar('-');
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	if (n <= -100 && n >= -999)
	{
		n = -(n);
		_putchar('-');
		_putchar((n / 100) + '0');
		_putchar(((n / 10) % 10) + '0');
		_putchar((n % 10) + '0');
	}
}
