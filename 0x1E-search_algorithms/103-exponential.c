#include "search_algos.h"

int binary_search2(int *array, int value, int low, int high);

/**
 * exponential_search - searches for a value in a sorted array
 * of integers using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: -1 if array is NULL or value not in array
 * or index of the value
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound;
	int low, high;

	if (!array)
		return (-1);

	bound = 1;
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < size - 1) ? bound : size - 1;

	printf("Value found between indexes [%d] and [%d]\n", low, high);

	return (binary_search2(array, value, low, high));
}

/**
 * binary_search2 - searches for a value in a sorted array
 * of integers using the Binary search algorithm
 * @array: a pointer to the first element of the array to search in
 * @value: the value to search for
 * @low: low point
 * @high: high point 
 * Return: -1 if value not in array or array is NULL
 * Else, return index of value
 */

int binary_search2(int *array, int value, int low, int high)
{
	int i, mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;

		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
			else
				printf("\n");
		}

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			low = mid + 1;

		else
			high = mid - 1;
	}

	return (-1);
}
