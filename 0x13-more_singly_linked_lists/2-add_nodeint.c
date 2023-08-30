#include "lists.h"

/**
 * add_nodeint - function that adds new node at beginning of listint_t list
 * @head: pointer to a pointer to a head of linked list
 * @n: holds the data for the node
 *
 *Return: the address of the new element or NULL on failure
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->next = *head;

	*head = new_node;
	return (new_node);
}
