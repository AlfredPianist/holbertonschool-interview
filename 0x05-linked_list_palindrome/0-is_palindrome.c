#include "lists.h"

/**
 * is_palindrome - checks if a linked list is palindrome.
 *
 * @head: the head of the linked list.
 *
 * Return: 1 if palindrome, otherwise 0.
 */
int is_palindrome(listint_t **head)
{
	if (!head)
		return (0);

	return (is_palindrome_helper(head, *head));
}

/**
 * is_palindrome_helper - recursive helper palindrome function.
 *
 * @left: the address to the left part of the linked list going forward.
 * @right: the right part of the linked list going backward.
 *
 * Return: 1 if palindrome, otherwise 0.
 */

int is_palindrome_helper(listint_t **left, listint_t *right)
{
	int is_palindrome;

	if (!right)
		return (1);

	is_palindrome = is_palindrome_helper(left, right->next);
	is_palindrome = is_palindrome && (right->n == (*left)->n);
	*left = (*left)->next;

	return (is_palindrome);
}
