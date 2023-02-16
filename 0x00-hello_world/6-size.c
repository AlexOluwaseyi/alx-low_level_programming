#include <stdio.h>
/**
 * This a program which prints the size of various types
 * on the computer it is compiled and run on.
 *
 * int main(void) - Entry point
 *
 * return (0) when successful.
 *
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
