#include <stdio.h>
#include "main.h"
/**
 * output3 - a collection of _putchar
 * output2 - a collection of _putchar
 * output4 - a collection of _putchar
 * print_times_table - prints the multiplication table from 0 to 9
 * @n: Limit of multiplication table
 */

int i = 0;
int j = 0;
int prod = i * j;

void output3();
void output2();
void output4();

void print_times_table(int n)
{
	if ((n < 0) || (n > 15))
		return;
	else
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				if (i == 0)
				{
					_putchar(prod + '0');
					for (j = 0; j <= (n - 1); j++)
					{
						output3();
					}
				}
				else if (prod == 0)
					_putchar(prod + '0');
				else if (prod < 10)
				{
					output3();
				}
				else if ((prod >= 10) && (prod < 100))
				{
					output2();
				}
				else if (prod >= 100)
				{
					output4();
				}
			}
			_putchar('\n');
		}
	}
}
void output3(void)
{
	_putchar(',');
	_putchar(' ');
	_putchar(' ');
	_putchar(' ');
	_putchar(prod + '0');
}
void output2(void)
{
	int prod;
	
	_putchar(',');
	_putchar(' ');
	_putchar(' ');
	_putchar((prod / 10) + '0');
	_putchar((prod % 10) + '0');
}
void output4(void)
{
	int prod;
       
	_putchar(',');
       	_putchar(' ');
       	_putchar((prod / 100) + '0');
       	_putchar(((prod / 10) % 10) + '0');
       	_putchar((prod % 10) + '0');
}
