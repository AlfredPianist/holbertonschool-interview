#include "search_algos.h"

/**
 * advanced_binary - Search for a value within an array with recursive
 *                   binary search.
 * @array: The array to be searched.
 * @size: The size of the array.
 * @value: The value to be searched.
 *
 * Return: The index of the value searched if found. Return -1 otherwise.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (binary_search_helper(array, value, 0, size - 1));
}

/**
 * binary_search_helper - The actual recursive binary search algorithm.
 * @array: The array to be searched.
 * @value: The value to be searched.
 * @left_idx: The leftmost index of the subarray.
 * @right_idx: The rightmost index of the subarray.
 *
 * Return: The index of the value searched if found. Return -1 otherwise.
 */
int binary_search_helper(int *array, int value,
			 size_t left_idx, size_t right_idx)
{
	size_t middle;

	middle = (right_idx + left_idx) / 2;

	if (left_idx == right_idx)
	{
		if (array[middle] == value)
			return (middle);
		print_subarray(array, left_idx, right_idx);
		return (-1);
	}

	print_subarray(array, left_idx, right_idx);
	if (array[middle] < value)
		return (binary_search_helper(array, value, middle + 1, right_idx));
	return (binary_search_helper(array, value, left_idx, middle));
}

/**
 * print_subarray - Prints the elements of a given subarray
 * @array: The array to be printed.
 * @left_idx: The left index of the subarray.
 * @right_idx: The right index of the subarray.
 */
void print_subarray(int *array, size_t left_idx, size_t right_idx)
{
	printf("Searching in array: ");
	for (; left_idx <= right_idx; left_idx++)
	{
		printf("%d", array[left_idx]);
		if (left_idx != right_idx)
			printf(", ");
	}
	printf("\n");
}
