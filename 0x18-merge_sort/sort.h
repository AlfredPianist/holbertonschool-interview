#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);

void merge_sort(int *array, size_t size);
void merge_recursive(int *array, int *array_cpy, size_t size);
void merge_arrays(int *array, int *array_cpy_l, size_t size_l, size_t size_r);

#endif
