#include "lists.h"

/**
 * sum_dlistint - unction that returns the sum of all
 *		the data (n) of a dlistint_t linked list
 * @head: header of a doubly-linked list
 * Return: Sum of all data(n), 0 if list is empty
 *
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum = 0;

	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}

