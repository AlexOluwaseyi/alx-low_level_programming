#include "main.h"

/**
 * set_bit - sets bit at index to 1
 * @n: integer to be converted to decimal
 * @index: index at which bit is to be changed to 1
 *
 * Return: 1 on succes and -1 if otherwise
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = *n | 1ul << index;
	return (1);
}
