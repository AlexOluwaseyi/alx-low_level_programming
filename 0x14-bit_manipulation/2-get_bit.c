#include "main.h"

/**
 * get_bit - gets bit of a binary at index
 * @n: number to be converted to binary
 * @index: location of bit to return
 *
 * Return: Value at index
 * or -1 if error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int m;

	if (index > 63)
		return (-1);

	m = 1 << index;
	return ((n & m) > 0);
}
