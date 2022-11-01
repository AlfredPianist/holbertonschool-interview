#include "list.h"

/**
 * add_node_end - Add a new node to the end of
 * .              a double circular linked list.
 * @list: List to modify.
 * @str: String to copy to the new node.
 *
 * Return: Address of new node or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	if (*list == NULL)
	{
		*list = create_node(NULL, NULL, str);
		if (*list != NULL)
		{
			(*list)->prev = *list;
			(*list)->next = *list;
		}
		return (*list);
	}

	(*list)->prev->next = create_node((*list)->prev, *list, str);
	(*list)->prev = (*list)->prev->next;

	return ((*list)->prev);
}

/**
 * add_node_begin - Add a new node to the beginning of
 * .                a double circular linked list.
 * @list: List to modify.
 * @str: String to copy to the new node.
 *
 * Return: Address of new node or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	*list = add_node_end(list, str);
	return (*list);
}

/**
 * create_node - Creates a new node for the
 *               double circular linked list.
 * @prev: The new node's previous node.
 * @next: The new node's next node.
 * @str: The string to be copied to the new node.
 *
 * Return: Address of new node or NULL on failure.
 */
List *create_node(List *prev, List *next, char *str)
{
	List *new_node;

	if (str == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->prev = prev;
	new_node->next = next;

	return (new_node);
}
