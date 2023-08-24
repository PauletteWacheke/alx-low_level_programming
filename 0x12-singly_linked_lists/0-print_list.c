#include "lists.h"
/**
 * print_list - function that prints all elements oa a list_t list.
 * @h: pointer
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t tally = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf(" [%u] %s\n", h->len, h->str);
		}
		h = h->next;
		tally++;
	}

	return tally;
}
