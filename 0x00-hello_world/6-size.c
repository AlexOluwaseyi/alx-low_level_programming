#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char CHAR;
	int INT;
	long LONG;
	long long LLONG;
	float FLOAT;

	printf("Size of a char: %d byte(s)\n", sizeof(CHAR));
	printf("Size of an int: %d byte(s)\n", sizeof(INT));
	printf("Size of a long int: %d byte(s)\n", sizeof(LONG));
	printf("Size of a long long int: %d byte(s)\n", sizeof(LLONG));
	printf("Size of a float: %d byte(s)\n", sizeof(FLOAT));
	return (0);
}
