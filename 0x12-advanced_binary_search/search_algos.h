#ifndef SEARCH_ALGOS
#define SEARCH_ALGOS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_subarray(int *array, size_t left_idx, size_t right_idx);
int binary_search_helper(int *array, int value,
			 size_t left_idx, size_t right_idx);
int advanced_binary(int *array, size_t size, int value);

#endif
