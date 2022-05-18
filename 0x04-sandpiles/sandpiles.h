#ifndef SANDPILES
#define SANDPILES

#include <stdio.h>

static void print_grid(int grid[3][3]);
void sum_grids(int grid1[3][3], int grid2[3][3]);
int is_grid_stable(int grid[3][3]);
void topple_sand(int grid[3][3], int grid_tmp[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
