#include "lists.h"

/**
 * get_dnodeint_at_index - function that returns the nth node
 *			of a dlistint_t linked list.
 * @head: header of a doubly-linked list
 * @index: index of the node, starting from 0
 * Return: Pointer to the nth node, NULL if node doesnt exist
 *
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int count = 0;

	current = head;
	while (current != NULL)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}

	return (NULL);
}

