#include "main.h"

/**
 * _calloc - allocates memory for an array nmemb elements of size
 * @nmemb: number element(s)
 * @size: size of allocated memory for each member
 * Return: NULL if malloc fails, or if nmemb or size is 0.
 * Else, return pointer to allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0 ; i < (nmemb * size); i++)
		ptr[i] = 0;
	return (ptr);
}
