#include "main.h"

/**
 * free_grid - free a 2 dimensional grid created by alloc_grid
 * @grid: 2 dimensional grid created by alloc_grid
 * @height: height of grid
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
