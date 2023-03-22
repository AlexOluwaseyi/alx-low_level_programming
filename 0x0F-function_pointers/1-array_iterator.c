#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an array
 * @array: the array to be iterated
 * @size: Size of the array.
 * @action: pointer to the function to be used
 * Return: void.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned long int i = 0;

	if (array == NULL || action == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
