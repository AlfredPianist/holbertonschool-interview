#include "lists.h"

/**
 * check_cycle- Checks if a singly linked list has a cycle in it.
 * @list: The list's head.
 *
 * Return: 1 if singly linked list has a cycle. 0 otherwise.
 */
int check_cycle(listint_t *list)
{
	listint_t *uro, *boros;

	if (!list)
		return (0);

	uro = list;
	boros = list;

	while (uro && uro->next)
	{
		uro = uro->next->next;
		boros = boros->next;
		if (uro == boros)
			return (1);
	}
	return (0);
}
