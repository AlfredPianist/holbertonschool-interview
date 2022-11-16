#!/usr/bin/python3
"""Calculate the perimeter of an island."""


def island_perimeter(grid):
    """Function that calculates the perimeter of an island.
    Args:
        grid (list of list of int): 1 represents land, 0 represents water.
    Returns:
        int: The perimeter of the island.
    """

    perimeter = 0
    for row in range(len(grid)):
        for sq in range(len(grid[row])):
            if grid[row][sq] == 1:
                perim_sq = 4
                if sq - 1 >= 0 and grid[row][sq - 1] == 1:
                    perim_sq -= 1
                if sq + 1 < len(grid[row]) and grid[row][sq + 1] == 1:
                    perim_sq -= 1
                if row - 1 >= 0 and grid[row - 1][sq] == 1:
                    perim_sq -= 1
                if row + 1 < len(grid) and grid[row + 1][sq] == 1:
                    perim_sq -= 1
                perimeter += perim_sq
    return perimeter
