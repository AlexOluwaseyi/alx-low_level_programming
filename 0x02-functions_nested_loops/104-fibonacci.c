#include <stdio.h>

/**
 * main - print the first 98 fibonacci numbers
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long prev = 1;
	unsigned long next = 2;
	unsigned long sum;
	int i;

	for (i = 0; i < 97; i++)
	{
		printf("%lu, ", prev);
		sum = prev + next;
		prev = next;
		next = sum;
	}
	printf("%lu\n", prev);
	return (0);
}
