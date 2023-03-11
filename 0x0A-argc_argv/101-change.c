#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Main program
 * @argc: number of command line arguments
 * @argv: command line argument(s)
 * Return: 0 - success
 */

int main(int argc, char *argv[])
{
	int cents = atoi(argv[1]);
	int change = 0;

	if (argc != 2 || argc == 1)
	{
		printf("Error\n");
		return (1);
	}
	if (cents <= 0)
	{
		printf("0\n");
		return (0);
	}
	else
	{
		change += cents / 25;
		cents %= 25;
		change += cents / 10;
		cents %= 10;
		change += cents / 5;
		cents %= 5;
		change += cents / 2;
		cents %= 2;
		change += cents;
	}
	printf("%d\n", change);
	return (0);
}
