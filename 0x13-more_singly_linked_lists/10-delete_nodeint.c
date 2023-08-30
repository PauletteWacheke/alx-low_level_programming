#include "lists.h"
/**
 * delete_nodeint_at_index - function that deletes the node at
 * index of listint_t list
 * @index: index of nide that should be deleted, index starts at 0.
 * @head: pointer to the address of the head of listint_t list
 *Return: 1 on success, -1 on failure
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *temp, *current = *head;

	if (current == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	for (i = 0; i < (index - 1); i++)
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
	}

	temp = current->next;
	current->next = temp->next;
	free(temp);
	return (1);
}

