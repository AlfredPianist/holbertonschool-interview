#include "search.h"

/**
 * linear_skip - Search for the first occurrence of a value on a singly-linked
 *               list using a skip list that itself is implemented with the
 *               optimal step: sqrt(total_nodes).
 * @list: The head of the list to be searched.
 * @value: The value to be searched.
 *
 * Return: The pointer of the node with the value searched if found.
 *         Return NULL otherwise.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *lo_ptr, *hi_ptr;

	if (!list)
		return (NULL);

	lo_ptr = list;
	hi_ptr = list->express;

	while (1)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       hi_ptr->index, hi_ptr->n);
		if (hi_ptr->next &&
		    !(value >= lo_ptr->n && value <= hi_ptr->n))
		{
			lo_ptr = hi_ptr;
			if (hi_ptr->express)
				hi_ptr = hi_ptr->express;
			else
			{
				for (; hi_ptr->next; hi_ptr = hi_ptr->next)
					;
				break;
			}
		}
		else
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       lo_ptr->index, hi_ptr->index);

	for (; lo_ptr; lo_ptr = lo_ptr->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       lo_ptr->index, lo_ptr->n);
		if (value == lo_ptr->n)
			return (lo_ptr);
	}
	return (NULL);
}
