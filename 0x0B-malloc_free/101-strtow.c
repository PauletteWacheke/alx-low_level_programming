#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * strtow - function that splits a string into words
 * @str: string to be splited.
 *
 * Return: pointer to an arrat of strings(words) or NULL on failure.
 */
char **strtow(char *str)
{
	int i;
	int k = 0;
	int words = 0;
	int word_index = 0;
	char *word;
	char **word_array = NULL;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			words++;

			while (str[i] && str[i] != ' ')
				i++;
		}
	}

	if (words == 0)
		return (NULL);

	word_array = (char **)malloc((words + 1) * sizeof(char *));

	if (word_array == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			int word_length = 0;
			int j = i;

			while (str[j] && str[j] != ' ')
			{
				word_length++;
				j++;
			}

			word = (char *)malloc((word_length + 1) * sizeof(char));
			if (word == NULL)
			{
				for (k = 0; k < word_index; k++)
					free(word_array[k]);
				free(word_array);
				return (NULL);
			}

			while (i < j)
			{
				word[k] = str[i];
				k++;
				i++;
			}
			word[k] = '\0';
			word_array[word_index] = word;
			word_index++;
		}
	}

	word_array[word_index] = NULL;
	return (word_array);
	free(word_array);
}

