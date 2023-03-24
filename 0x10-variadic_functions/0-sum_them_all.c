#include "variadic_functions.h"

/**
 * sum_them_all - sums up all its parameters
 * @n: number of arguments
 * Return: sum
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i = 0;
	int result = 0;

	va_start(ap, n);
	for (i = 0; i < n; i++)
		result += va_arg(ap, int);
	va_end(ap);
	return (result);
}
