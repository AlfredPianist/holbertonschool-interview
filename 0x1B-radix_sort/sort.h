#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);

void radix_sort(int *array, size_t size);
int get_digit(int num, int digit);
listint_t *push(listint_t **bucket, listint_t **tail, int num);
int pop(listint_t **bucket, listint_t **tail);
void free_list(listint_t *list);

#endif
