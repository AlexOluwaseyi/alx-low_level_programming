#include <stdio.h>
#include <stdlib.h>

/**
 * main - Main program
 * @argc: Arguments passes to run program
 * @argv: Number of arguments passed
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int i = 0;

	i += atoi(argv[0]);
	printf("%d\n", argc - 1);
	return (0);
}
