#include <stdio.h>

/**
 * main - prints the sum of natural number between
 * 0 and 1024 (excluded) divisible by 3 and 5
 *
 * Return: Always 0.
 */
int main(void)
{
	int i, sum;

	for (i = 0; i <= 1023; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
			sum += i;
	}
	printf("%d\n", sum);
	return (0);
}
