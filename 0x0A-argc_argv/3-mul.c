#include <stdlib.h>
#include <stdio.h>

/**
 * main - Main program
 * @argc: program argument(s)
 * @argv: number of argument(s)
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int i = 0;
	int product;

	i += argc;
	if (argc == 3)
	{
		product = atoi(argv[1]) * atoi(argv[2]);
		printf("%d\n", product);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
