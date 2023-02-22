#include <stdio.h>
#include "main.h"
/**
 * print_times_table - prints the multiplication table from 0 to 9
 * @n: Limit of multiplication table
 */
void output3()
{
	_putchar(',');
	_putchar(' ');
	_putchar(' ');
	_putchar(' ');
}
void output2()
{
	_putchar(',');
	_putchar(' ');
	_putchar(' ');
}
void print_times_table(int n)
{
	int i, j, prod;

	if ((n < 0) || (n > 15))
	{
	}
	else
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				prod = i * j;
				if (i == 0)
				{
					_putchar(prod + '0');
					for (j = 0; j <= (n - 1); j++)
					{
						output3();
						_putchar(prod + '0');
					}
				}
				else if (prod == 0)
					_putchar(prod + '0');
				else if (prod < 10)
				{
					output3();
					_putchar(prod + '0');
				}
				else if ((prod >= 10) && (prod < 100))
				{
					output2();
					_putchar((prod / 10) + '0');
					_putchar((prod % 10) + '0');
				}
				else if (prod >= 100)
				{
					_putchar(',');
					_putchar(' ');
					_putchar((prod / 100) + '0');
					_putchar(((prod / 10) % 10) + '0');
					_putchar((prod % 10) + '0');
				}
			}
			_putchar('\n');
		}
	}
}
