#include "main.h"
#include <malloc.h>

/**
 * _realloc - dynamically reallocate memory to a pointer
 * @ptr: a pointer to the memory previously allocated with malloc()
 * @old_size: size of previously allocated memory
 * @new_size: new size of hte new memory block
 *
 * Return: NULL if new_size = 0 and ptr is not NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == old_size)
		return (ptr);
	if (new_size > old_size)
		ptr = realloc(ptr, new_size);
	if (ptr == NULL)
		ptr = malloc(new_size);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
