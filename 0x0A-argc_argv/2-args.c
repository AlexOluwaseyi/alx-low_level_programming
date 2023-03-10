#include <stdio.h>
#include <stdlib.h>

/**
 * main - Main program
 * @argc: Program of argument(s)
 * @argv: Number of Arguments passed
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
