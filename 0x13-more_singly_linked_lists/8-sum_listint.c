#include "lists.h"
/**
 * sum_listint - function that returns the sum of all data of listint_t list
 * @head: pointer to the head of the listint_t list
 *
 * Return: sum of all data of linked list or 0 if list is empty
 */

int sum_listint(listint_t *head)
{
	int sum;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
