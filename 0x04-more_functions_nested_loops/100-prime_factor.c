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
			printf("%d ", x);
			n /= x;
		}
	}
	printf("\n");
	return (0);
}
