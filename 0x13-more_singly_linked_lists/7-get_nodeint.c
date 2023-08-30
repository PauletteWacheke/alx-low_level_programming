#include "lists.h"
/**
 * get_nodeint_at_index - function that returns the nth node of listint_t list
 * @head: pointer to the head of listint_t list
 * @index: index of the node, starting at 0.
 *
 * Return: NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int current_index = 0;

	while (head != NULL)
	{
		if (current_index == index)
			return (head);

		current_index++;
		head = head->next;
	}

	return (NULL);
}
