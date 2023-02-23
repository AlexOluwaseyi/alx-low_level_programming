#include <stdio.h>
#include "main.h"

/**
 * print_numbers - prints numbers from 0 to 9 using _putchar
 */

void print_most_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		if (i != 2)
		{
			if (i != 4)
				_putchar(i + '0');
		}
	}
	_putchar('\n');
}
