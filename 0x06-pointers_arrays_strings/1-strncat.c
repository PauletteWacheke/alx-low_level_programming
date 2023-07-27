#include "main.h"
#include <string.h>

/**
 * _strncat - Entry point.
 * Description - concatenates two strings.
 * @dest: destination
 * @src: source
 * @n: number of bytes to concatenate.
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int len = strlen(dest);
	int i;

	 /*Append at most n bytes from the source string to the destination*/

	for (i = 0; i < n && *src != '\0'; i++)
	{
		dest[len + i] = *src;
		src++;
	}
	dest[len + i] = '\0';
	return (dest);

}
