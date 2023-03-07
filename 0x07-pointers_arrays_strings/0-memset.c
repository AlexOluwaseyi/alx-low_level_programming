#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: string buffer
 * @b: constant byte
 * @n: size of byte
 *
 * Return: pointer fo the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (i = 0; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
