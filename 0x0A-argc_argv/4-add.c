#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * main - Main program
 * @argc: program argument(s)
 * @argv: number of argument(s)
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int i;
	int sum = 0;

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			if (atoi(argv[i]))
			{
				sum += atoi(argv[i]);
			}
			else
			{
				printf("Error\n");
				return (1);
			}
		}
		printf("%d\n", sum);
	}
	else
		printf("%d\n", sum);
	return (0);
}
