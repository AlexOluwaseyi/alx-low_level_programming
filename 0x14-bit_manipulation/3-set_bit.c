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
	unsigned long int mask = 1;

	while (index > 0)
	{
		mask <<= 1;
		index--;
	}
	if (mask > *n)
	{
		return (-1);
	}
	*n |= mask;
	return (1);
}
