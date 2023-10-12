#include "lists.h"

/**
 * dlistint_len - function that returns the number of elements
 *		in a linked dlistint_t list.
 * @h: header of doubly linked list
 * Return: number of elements of the list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}
	return (nodes);
}
