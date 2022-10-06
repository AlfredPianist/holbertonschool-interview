#include "lists.h"

/**
 * find_listint_loop - Returns the address of the node when the loop starts
 *                     on a circular singly linked list, NULL if head doesn't
 *                     exist or not a circular singly linked list.
 * @head: The list's head.
 *
 * Return: The address of the node when the loop starts, or NULL if head non-
 *         existent or not a circular singly linked list.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *uro, *boros;

	if (head == NULL)
		return (NULL);

	uro = head;
	boros = head;

	while (1)
	{
		if (uro == NULL || uro->next == NULL)
			return (NULL);
		uro = uro->next->next;
		boros = boros->next;
		if (uro == boros)
			break;
	}

	boros = head;

	while (uro != boros)
	{
		uro = uro->next;
		boros = boros->next;
	}

	return (boros);
}
