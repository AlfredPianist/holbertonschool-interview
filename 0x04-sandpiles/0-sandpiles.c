#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (column)
				printf(" ");
			printf("%d", grid[row][column]);
		}
		printf("\n");
	}
}

/**
 * sum_grids - sums two grids. Stores sum in first grid, second grid
 *			   ends initialized on 0 for future computations.
 *
 * @grid1: first grid.
 * @grid2: second grid.
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
		{
			grid1[row][column] += grid2[row][column];
			grid2[row][column] = 0;
		}
}

/**
 * is_grid_stable - calculates if the grid is unstable (a value is more
 *					than 3)
 *
 * @grid: the grid to be calculated.
 *
 * Return: 1 if stable, 0 otherwise.
 */
int is_grid_stable(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
			if (grid[row][column] > 3)
				return (0);
	return (1);
}

/**
 * topple_sand - Topples sand to adjacent, non diagonal tiles.
 *
 * @grid: the original grid.
 * @grid_tmp: the grid result of the toppling.
 */
void topple_sand(int grid[3][3], int grid_tmp[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > 3)
			{
				grid[row][column] -= 4;
				if (row > 0)
					grid_tmp[row - 1][column] += 1;
				if (row < 2)
					grid_tmp[row + 1][column] += 1;
				if (column > 0)
					grid_tmp[row][column - 1] += 1;
				if (column < 2)
					grid_tmp[row][column + 1] += 1;
			}
		}
	}

	sum_grids(grid, grid_tmp);
}

/**
 * sandpiles_sum - sum two sandpiles. Here's more information about
 *				   the sandpiles.
 *
 * @grid1: the first grid.
 * @grid2: the second grid.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (!is_grid_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple_sand(grid1, grid2);
	}
}
