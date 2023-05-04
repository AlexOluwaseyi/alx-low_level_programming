#include "main.h"

/**
 * set_bit - sets bit at index to 1
 * @n: integer to be converted to decimal
 * @index: index at which bit is to be chaged to 1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index > (sizeof(unsigned long int) * 8) - 1)
		return (-1);

	mask <<= index;
	*n |= mask;
	return (1);
}
