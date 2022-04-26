#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a node in a sorted linked list.
 * @head: the head of the linked list.
 * @number: the number to be inserted.
 * Return: the address of the newly inserted node or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current_node = *head;
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);
	new_node->n = number;

	if (number < current_node->n)
	{
		new_node->next = current_node;
		*head = new_node;
		return (*head);
	}

	while (current_node->next && current_node->next->n < number)
		current_node = current_node->next;

	if (current_node->next)
		new_node->next = current_node->next;
	else
		new_node->next = NULL;

	current_node->next = new_node;

	return (new_node);
}
