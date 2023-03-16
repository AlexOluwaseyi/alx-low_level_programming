#include "main.h"

/**
 * array_range - create and array of integer
 * @min: minimum value in array (inclusive)
 * @max: maximum value in array (inclusive)
 *
 * Return: pointer to newly created array
 * Or NULL if malloc fails or if min > max
 */

int *array_range(int min, int max)
{
	int i;
	int *ptr;
	void *null = NULL;
	int value = min;

	if (min > max)
		return (null);
	ptr = malloc(sizeof(int) * (max - min + 1));
	if (ptr == NULL)
		return (null);
	for (i = 0; i < (max - min + 1); i++)
	{
		ptr[i] = value;
		value++;
	}
	return (ptr);
}
