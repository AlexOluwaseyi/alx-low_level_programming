#include "main.h"

/**
 * clear_bit - clears bit at index to 0
 * @n: pointer to integer number
 * @index: index of bit to be changed to 0
 * Return: 1 if successful and -1 if otherwise
 */

int clear_bit(unsigned long int *n, unsigned int index)
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
	*n ^= mask;
	return (1);
}
