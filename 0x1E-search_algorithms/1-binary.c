#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array
 * of integers using the Binary search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: -1 if value not in array or array is NULL
 * Else, return index of value
 */

int binary_search(int *array, size_t size, int value)
{
	int first = 0;
	int last = size - 1;
	int i, mid;

	while (first <= last)
	{
		mid = first + (last - first) / 2;

		printf("Searching in array: ");
		for (i = first; i <= last; i++)
		{
			printf("%d", array[i]);
			if (i < last)
				printf(", ");
			else
				printf("\n");
		}

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			first = mid + 1;

		else
			last = mid - 1;
	}

	return (-1);
}
