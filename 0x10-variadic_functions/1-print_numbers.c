#include "variadic_functions.h"

/**
 * print_numbers - prints numbers separated by a separator
 * @separator: separates the numbers
 * @n: number of arguments
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i = 0;

	va_start(ap, n);
	for (i = 0; i < (n - 1); i++)
	{
		printf("%d", va_arg(ap, int));
		if ((void *)separator != NULL)
		{
			printf("%c ", *separator);
		}	
	}
	printf("%d", va_arg(ap, int));
	printf("\n");
	va_end(ap);
}
