#include "lists.h"

/**
 * add_dnodeint_end - function that adds a new node
 *		at the end of a dlistint_t list.
 * @head: header of doubly-linked list
 * @n: number to set in a new node
 * Return:address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *end;

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	end = *head;

	while (end->next != NULL)
		end = end->next;

	end->next = new;
	new->prev = end;

	return (new);
}
