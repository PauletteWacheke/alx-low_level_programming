#include <stdlib.h>
#include "main.h"
/**
 * argstostr - function that concatenates all arguments of the program
 * @ac: number of arguments.
 * @av: array of arguments.
 *
 * Return: Pointer to the concatenated strign or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int i, j, len = 0, total_len = 0;
	char *concatenate;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		total_len += len + 1;
	}

	concatenate = malloc(sizeof(char) * len + 1);
	if (concatenate == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			*concatenate = av[i][j];
			concatenate++;
		}
		*concatenate = '\n';
		concatenate++;
	}
	*concatenate = '\0';
	return (concatenate - total_len);
}
