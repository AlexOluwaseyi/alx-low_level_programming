#include "main.h"
#include <math.h>
#include <ctype.h>

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: arguments passed to command line
 * 
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	unsigned long mul = 1;
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	else if (argc == 3)
	{
		for (i = 1; i < argc; i++)
		{
			for (j = 0; argv[i][j] != '\0'; j++)
			{
				if (isdigit(argv[i][j]))
				{
					continue;
				}
				else
				{
					printf("Error\n");
					exit(98);
				}
			}
			mul = num1 * num2;
		}
		printf("%lu\n", mul);
	}
	return (0);
}
