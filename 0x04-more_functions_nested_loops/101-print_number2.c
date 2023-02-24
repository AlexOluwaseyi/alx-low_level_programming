#include <stdio.h>
#include "main.h"

/**
 * print_number - prints out an integer using _putchar
 * @n: number to be printed
 */

void print_number(int n)
{
	if ((n >= 0) && (n < 10))
	{
		_putchar(n + '0');
	}
	else if ((n >= 10) && (n <= 99))
	{
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else if ((n >= 100) && (n <= 999))
	{
		_putchar((n / 100) + '0');
		_putchar(((n / 10) % 10) + '0');
		_putchar((n % 10) + '0');
	}
	else if ((n >= 1000) && (n <= 9999))
	{
		_putchar((n / 1000) + '0');
		_putchar(((n % 1000) / 100) + '0');
		_putchar(((n % 100) / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else if ((n < 0) && (n >= -99))
	{
		n *= -1;
		_putchar('-');
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
}
