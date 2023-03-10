#include <stdio.h>

/**
 * main - Main program
 * @argc: program argument(s)
 * @argv: numbers of argument(s)
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int i = 0;

	i += argc;
	printf("%s\n", argv[0]);
	return (0);
}
