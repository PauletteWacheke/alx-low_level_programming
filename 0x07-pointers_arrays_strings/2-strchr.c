#include "main.h"
/**
 * _strchr - function that locates a character in a string
 *
 * @s: string
 * @c: character in s
 * Return: pointer to 1st occurence or NULL
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	if (s[i] == c)
		return (s + i);
	else
		return ('\0');
}

