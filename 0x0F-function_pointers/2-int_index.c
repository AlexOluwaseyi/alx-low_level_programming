#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array to search in
 * @size: size or number of elements in array
 * @cmp: pointer to function to be used to compare value
 * Return: -1 if no element matches or if size <= 0
 * Else return the index of the element for which cmp does not return 0.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
		{
			return (i);
		}
	}
	return (-1);
}
