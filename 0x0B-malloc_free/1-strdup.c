#include <stdlib.h>
#include "main.h"
/**
 * _strdup - function that returns a pointer to a newly allocated space in
 * memory which contains a copy of the string given as a parameter
 * @str: holds the string to be duplicated
 *
 * Return: pointer to the duplicated string or NULL if fails.
 */
char *_strdup(char *str)
{
	char *p; /*new duplicated string*/
	int i;  /* to track the length of th einput string*/
	int j;  /*index for copying characters*/

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i += 1;
	p = malloc(i * sizeof(char) + 1);

	if (p == NULL)
		return (NULL);
	while (*str)
	{
		p[j] = *str;
		str++;
		j += 1;
	}
	p[j] = *str;
	return (p);
	free(p);
}

