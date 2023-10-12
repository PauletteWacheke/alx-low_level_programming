#include "lists.h"

/**
 * print_dlistint - function that prints all elements of a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (nodes);
}
