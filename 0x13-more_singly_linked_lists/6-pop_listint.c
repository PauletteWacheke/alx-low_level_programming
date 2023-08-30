#include "lists.h"
/**
 * pop_listint - function that deletes the head node of listint_t linked list
 * @head: pointer to  the address of head of listint_t list
 *
 * Return: the head node's data(n) or 0 if linked list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data;

	if (*head == NULL)
		return (0);

	temp = *head;
	data = (*head)->n;
	*head = (*head)->next;

	free(temp);

	return (data);
}

