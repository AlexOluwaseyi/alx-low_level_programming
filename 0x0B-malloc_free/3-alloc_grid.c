#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: Width of the array
 * @height: Height of the array
 * Return: On success - pointer to array.
 * On failure, return NULL.
 */

int **alloc_grid(int width, int height)
{
	int **mee;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);
	mee = malloc(sizeof(int *) * height);
	if (mee == NULL)
		return (NULL);
	for (x = 0; x < height; x++)
	{
		mee[x] = malloc(sizeof(int) * width);
		if (mee[x] == NULL)
		{
			for (; x >= 0; x--)
			free(mee[x]);
			free(mee);
			return (NULL);
		}
	}
	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
		mee[x][y] = 0;
	}
	return (mee);
}
