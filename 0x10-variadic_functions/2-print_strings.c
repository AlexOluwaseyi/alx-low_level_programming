#include "variadic_functions.h"

/**
 * print_strings - prints the strings pass to the function
 * @separator: separates the two strings
 * @n: number of arguments
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *Array;

	va_start(ap, n);
	for (i = 0; i < (n - 1); i++)
	{
		Array = va_arg(ap, char *);
		if (Array == NULL)
			printf("(nil)");
		else
			printf("%s", Array);
		if ((void *)separator != NULL)
			printf("%s", separator);
	}
	printf("%s", va_arg(ap, char *));
	printf("\n");
}
