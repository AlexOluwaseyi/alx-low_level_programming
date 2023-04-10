#include "main.h"

/**
 * flip_bits - counts the number of bit to flip to get another number
 * @n: first integer
 * @m: second integer
 * Return: Number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x = n ^ m;
	unsigned int count = 0;
	while (x != 0)
	{
		count += x & 1;
		x >>=1;
	}
	return (count);
}
