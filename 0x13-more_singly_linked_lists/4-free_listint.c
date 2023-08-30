#include "lists.h"
/**
 * free_listint - function that frees a listint_t list
 * @head: pointer point to the head of a list
*/
void free_listint(listint_t *head)
{
	while (head != NULL)
	{
		listint_t *temp = head;

		head = head->next;
		free(temp);
	}
}

