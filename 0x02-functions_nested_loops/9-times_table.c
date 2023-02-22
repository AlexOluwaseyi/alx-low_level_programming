#include <stdio.h>
#include "main.h"

/**
 * times_table - prints the multiplication table from 0 to 9
 */
void times_table(void)
{
	int i, j, prod;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			prod = i;
			prod *= j;
			if (prod == 0)
			{
				_putchar(prod + '0');
			}
			else if (prod < 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(prod + '0');
			}
			else if (prod >= 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar((prod / 10) + '0');
				_putchar((prod % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
