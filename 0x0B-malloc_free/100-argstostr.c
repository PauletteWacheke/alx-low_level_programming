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
	int i, j, len = 0, k = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		len++;
	}
	len += ac;

	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[k] = av[i][j];
			k++;
		}

		if (str[k] == '\0')
		{
			str[k++] = '\n';
		}

	}

	return (str);
}
