#include "lists.h"

/**
 * free_list - frees linked ist
 * @head: pointer to head of linked list
 *
 * Return: nothing
 */

void free_list(list_t *head)
{
	while (head != NULL)
	{
		free(head->str);
		free(head);
		head = head->next;
	}
}

