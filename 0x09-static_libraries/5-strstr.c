#include "main.h"
/**
 * _strstr - functions that locates a sucstring
 * @haystack: string
 * @needle: substring
 *
 * Return: pointer to the beginning of the located
 * substring or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, l;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (l = i, j = 0; needle[j] != '\0'; j++, l++)
		{
			if (needle[j] != haystack[l] || haystack[l] == '\0')
			{
				break;
			}
		}
		if (needle[j] == '\0')
		{
			return (haystack + i);
		}
	}
	return (0);
}
