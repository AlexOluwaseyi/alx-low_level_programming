#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 * @b: pointer to address
 *
 * Return: pointer to allocated memory
 * Or cause normal process termination if malloc fails.
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
