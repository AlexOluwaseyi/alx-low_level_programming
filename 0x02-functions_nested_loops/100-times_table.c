#include <stdio.h>
#include "main.h"

/**
 * times_table - prints the multiplication table from 0 to 9
 */
void print_times_table(int n)
{
	int i, j, prod;
	int x;

	
	if ((n < 0) || (n > 15))
	{
	}
	else
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				prod = i;
				prod *= j;
				if (i == 0)
				{
					_putchar(prod + '0');
					for (j = 0; j <= (n - 1); j++)
					{
						_putchar(',');
						_putchar(' ');
						_putchar(' ');
						_putchar(' ');
						_putchar(prod + '0');
					}
				}
				else if (prod == 0)
					_putchar(prod + '0');
				else if (prod < 10)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
					_putchar(prod + '0');
				}
				else if ((prod >= 10) && (prod < 100))
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar((prod / 10) + '0');
					_putchar((prod % 10) + '0');
				}
				else if (prod >= 100)
				{
					x = prod / 10;
					_putchar(',');
					_putchar(' ');
					_putchar((x / 10) + '0');
					_putchar((x % 10) + '0');
					_putchar((prod % 10) + '0');
				}
			}
			_putchar('\n');
		}
	}
}

