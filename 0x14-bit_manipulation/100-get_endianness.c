#include "main.h"

/**
 * get_endianness - check the endianness
 * Return: 0 for big endian and 1 for little endians
 */

int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *)&x;

	if (*c == 1)
	{
		return (1);
	}
	else
		return (0);
}
