#include "lists.h"
/**
 * insert_nodeint_at_index - function that inserts a
 * new node at a given position
 * @idx: index of the list where new node should be added, index starts at 0
 * @head: pointer to the address of the head of the listint_t list
 * @n: integer for the  new node to contain
 *
 * Return: address of new node or NULL on failure
 *
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node, *current = *head;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (i = 0; current != NULL && i < idx - 1; i++)
		current = current->next;
	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}


