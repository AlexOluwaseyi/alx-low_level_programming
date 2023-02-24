#include <stdio.h>

/**
 * main - Finds the prime factors of a number
 *
 * Return: 0.
 */

int main(void)
{
	unsigned long int n = 612852475143;
	unsigned int x;

	for (x = 2; x <= n; x++)
	{
		while (n % x == 0)
		{
			n /= x;
		}
	}
	printf("%d", x - 1);
	printf("\n");
	return (0);
}
