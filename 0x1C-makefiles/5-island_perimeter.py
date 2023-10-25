#!/usr/bin/python3

"""
A module to calculate the perimemter of an island
given by a grid.
"""


def island_perimeter(grid):
    """Calculates the perimeter of the island in the given grid.

    Args:
    grid: A list of lists of integers, where 0 represents water and 1
      represents land.

    Returns:
    The perimeter of the island, or 0 if there is no island.
    """

    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # For each land cell, we check its four neighboring cells
                # and add 1 to the perimeter for each neighboring water cell.
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1
                if i < rows - 1 and grid[i + 1][j] == 1:
                    perimeter -= 1
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                if j < cols - 1 and grid[i][j + 1] == 1:
                    perimeter -= 1

    return perimeter
