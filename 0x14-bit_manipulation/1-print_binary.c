#include "main.h"

/**
 * print_binary - converts decimal to binary
 * @n: decimal integer to be converted
 * Return: binary form of integer
 */

void print_binary(unsigned long int n)
{
	unsigned int mask = 2147483648;
	int bitCount = 0;
	int i;

	for (i = 0; i < 32; i++)
	{
		if ((n & mask) != 0)
		{
			bitCount = 1;
			_putchar('1');
		}
		else if (bitCount == 1)
		{
			_putchar('0');
		}
		n <<= 1;
	}
	if (bitCount == 0)
	{
		_putchar('0');
	}
}
