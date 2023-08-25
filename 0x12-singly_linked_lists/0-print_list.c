#include "lists.h"
/**
 * print_list - function that prints all elements oa a list_t list.
 * @h: linked list
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	unsigned int tally;

	tally = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf(" [%i] %s\n", h->len, h->str);
		}
		h = h->next;
		tally += 1;
	}

	return (tally);
}
