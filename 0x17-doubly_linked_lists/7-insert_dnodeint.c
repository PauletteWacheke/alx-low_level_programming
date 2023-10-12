#include "lists.h"

/**
 * insert_dnodeint_at_index - function inserts a new node at a given position
 *
 * @h: double pointer to head of list
 * @idx: index of list where the new node should be added. Index starts at 0
 * @n: data for new node
 *
 * Return: address of the new node, or NULL if it failed
 *
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int count = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
	{
		new_node = malloc(sizeof(dlistint_t));
		if (new_node == NULL)
			return (NULL);
		new_node->n = n;
		new_node->prev = NULL;
		new_node->next = *h;

		if (*h != NULL)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	current = *h;
	while (current != NULL)
	{
		if (count == idx)
		{
			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
				return (NULL);
			new_node->n = n;
			new_node->prev = current->prev;
			new_node->next = current;
			current->prev->next = new_node;
			current->prev = new_node;
			return (new_node);
		}
		current = current->next;
		count++;
	}
	return (NULL);
}
