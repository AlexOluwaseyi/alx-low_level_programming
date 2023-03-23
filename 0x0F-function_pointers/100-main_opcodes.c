#include <stdio.h>
#include <stdlib.h>

/**
 * main - main program
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int i = 0;
	char *p;
	int size;

	if (argc != 2 || argv[1][0] == '-')
	{
		printf("Error\n");
		exit(1);
	}
	size = atoi(argv[1]);

	p = (char *)main;
	for (i = 0; i < size; i++)
	{
		printf("%02x ", *(p + i) & 0xff);
	}
	printf("\n");
}
