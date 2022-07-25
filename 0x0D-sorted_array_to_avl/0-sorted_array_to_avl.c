#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 *
 * @parent: Parent node.
 * @value: New node's value.
 *
 * Return: The new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->left = new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;

	return (new_node);
}

/**
 * rec_sorted_array_to_avl - Converts a sorted array to an AVL tree.
 *                           Divide and conquer approach.
 *
 * @node: The parent node.
 * @array: The array to be converted.
 * @min: The leftmost limit of the subarray.
 * @max: The rightmost limit of the subarray.
 *
 * Return: pointer to the new root node of AVL or NULL otherwise.
 */
avl_t *rec_sorted_array_to_avl(avl_t *node, int *array, int min, int max)
{
	avl_t *new;

	if (min > max)
		return (NULL);

	new = (avl_t *) binary_tree_node((avl_t *) node, array[(min + max) / 2]);
	if (!new)
		return (NULL);

	new->left = rec_sorted_array_to_avl(new, array,
					    min, ((min + max) / 2) - 1);
	new->right = rec_sorted_array_to_avl(new, array,
					     ((min + max) / 2) + 1, max);

	return (new);
}

/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree.
 *
 * @array: The array to be converted.
 * @size: The size of the array.
 *
 * Return: pointer to the new root node of AVL or NULL otherwise.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (rec_sorted_array_to_avl(NULL, array, 0, size - 1));
}
