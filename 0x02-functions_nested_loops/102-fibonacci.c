#include <stdio.h>

/**
 * main - print the first 50 fibonacci numbers
 *
 * Return: Always 0.
 */
int main(void)
{
	int prev = 1;
	int next = 2;
	int i, sum;

	for (i = 0; i < 47; i++)
	{
		printf("%d, ", prev);
		sum = prev + next;
		prev = next;
		next = sum;
	}
	printf("%d\n", prev);
	return (0);
}
