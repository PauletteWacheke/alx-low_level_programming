#include "main.h"

/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb: unsigned int
 * @size: unsigned int
 * Return: on success a pointer to allocated memory, NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmemb);

	if  (ptr == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i += 1)
		*(ptr + i) = 0;
	return (ptr);
}
