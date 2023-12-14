#include "search_algos.h"

int advanced_binary_recursive(int *array, size_t start, size_t end, int value);


/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the index where value is located,
 * or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}

/**
 * advanced_binary_recursive - recursively searches for a value in sorted array
 * @array: pointer to the first element of the array to search in
 * @start: the starting index of the search range
 * @end: the ending index of the search range
 * @value: the value to search for
 * Return: the index where value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t start, size_t end, int value)
{
	size_t mid, i;

	if (start > end)
		return (-1);

	printf("Searching in array: ");
	for (i = start; i < end; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	mid = start + (end - start) / 2;

	if (array[mid] == value)
	{
		if (mid > 0 && array[mid - 1] == value)
			return (advanced_binary_recursive(array, start, mid, value));
		return (mid);
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, end, value));
	else
		return (advanced_binary_recursive(array, start, mid, value));
}

