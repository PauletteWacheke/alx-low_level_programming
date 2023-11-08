#include "hash_tables.h"

/**
 * hash_table_print - function that prints a hash table
 *
 * @ht: hash table to print
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node = NULL;
	unsigned long int i = 0;
	char *comm = "";

	if (ht)
	{
		printf("{");
		while (i < ht->size)
		{
			node = ht->array[i];
			while (node)
			{
			printf("%s", comm);
			comm = ", ";

			if (node->key)
				printf("'%s': '%s'", node->key, node->value);
			node = node->next;
			}
			i++;
		}
		printf("}\n");
	}
}
