#include "lists.h"
/**
 * free_listint2 - function that frees a listint_t list
 * @head: pointer to pointer that point to a list
 *
*/

void free_listint2(listint_t **head)
{
	while (*head != NULL)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}
