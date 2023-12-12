#include "search_algos.h"

/**
 * linear_search -  searches for a value in an array of integers
 * using the Linear search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: index where vlaue is located if found
 * Or -1 if array is NULL or value not in array
 */

int linear_search(int *array, size_t size, int value)
{
	size_t index;

	if (array == NULL)
	{
		return (-1);
	}

	for (index = 0; index < size; index++)
	{
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		if (array[index] == value)
			return (index);
	}
	return (-1);
}
