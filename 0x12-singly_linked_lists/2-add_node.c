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
	list_t *ret_list;
	unsigned int i;

	ret_list = malloc(sizeof(list_t));
	if (ret_list == NULL)
		return (NULL);
	copy_str = strdup(str);
	for (i = 0; str[i] != '\0';)
		i += 1;

	ret_list->str = copy_str;
	ret_list->next = *head;
	ret_list->len = i;
	*head = ret_list;
	return (*head);
}
