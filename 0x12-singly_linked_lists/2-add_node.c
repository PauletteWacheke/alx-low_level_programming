#include "lists.h"
#include <string.h>

/**
 * add_node - add a node to the beginning of linked _list
 * @head: pointer to linked_list
 * @str: string
 *
 * Return: linked_List
 */

list_t *add_node(list_t **head, const char *str)
{
	char *copy_str;
	list_t *return_list;
	unsigned int i;

	return_list = malloc(sizeof(list_t));
	if (return_list == NULL)
		return (NULL);
	copy_str = strdup(str);
	for (i = 0; str[i] != '\0';)
		i += 1;

	return_list->str = copy_str;
	return_list->next = *head;
	return_list->len = i;
	*head = return_list;
	return (*head);
}
