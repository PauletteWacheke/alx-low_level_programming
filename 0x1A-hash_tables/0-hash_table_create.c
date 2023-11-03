#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 *
 * @size: size of the array
 * Return: pointer to newly created hash table, NULL on failure
 *
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	unsigned long int i;

	new_table = malloc(sizeof(hash_table_t));

	if (new_table == NULL)
		return (NULL);

	new_table->array = malloc(sizeof(void *) * size);

	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		new_table->size = size;

	new_table->size = size;

	return (new_table);
}
