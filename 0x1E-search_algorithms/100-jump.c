#include "search_algos.h"
#include <math.h>

size_t min(size_t a, size_t b);


/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: index where value is located if found,
 * or -1 if not found or array is NULL
 */

int jump_search(int *array, size_t size, int value)
{
	size_t jump;
	size_t prev = 0;
	size_t index = 0;

	if (!array)
		return (-1);

	jump = sqrt(size);
	if (index < size)
	{
		while (prev < jump || array[prev] < value)
		{
			printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
			index = prev;
			prev += jump;
		}

		if (value >= array[index] && value <= array[min(index + jump, size - 1)])

		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					index, min(index + jump, size - 1));
			for (; index < min(prev + jump, size - 1); ++index)
			{
				printf("Value checked array[%lu] = [%d]\n", index, array[index]);
				if (array[index] == value)
					return (index);
			}
		}

		else
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					index - jump, (index));
			printf("Value checked array[%lu] = [%d]\n", index, array[index]);
		}
	}
	return (-1);
}

/**
 * min - finds the minimum of two numbers
 * @a: first number
 * @b: second number
 * Return: minimum of a and b
 */

size_t min(size_t a, size_t b)
{
	return (a < b ? a : b);
}
