#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void print_array(const int *array, size_t size);

void heap_sort(int *array, size_t size);
void build_heap(int *array, size_t size);
void sift_down(int *array, size_t size, size_t i, size_t osize);
void swap(int *num_1, int *num_2);

#endif
