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
	unsigned long int mask = 1;
	unsigned long int num_bits = 0;
	unsigned long int copy_n = n;

	while (copy_n > 0)
	{
		copy_n >>= 1;
		num_bits++;
	}
	if (index >= num_bits)
	{
		return (-1);
	}
	mask <<= index;
	if ((n & mask) != 0)
	{
		return (1);
	}
	else
		return (0);
}
