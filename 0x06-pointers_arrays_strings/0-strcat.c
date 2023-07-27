#include "main.h"
#include <stdio.h>
/**
 * _strcat - Entry point
 * Description - appends the src string to the dest string, overwriting the
 * terminating null byte (\0) at the end of dest, and then adds
 * a terminating null byte.
 *
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	/*find the length of destination string*/
	int destlen = 0;
	int srclen = 0;
	int i;

	for (i = 0; dest[i] != '\0'; i++)
		destlen++;
	/*find length of source string*/
	for (i = 0; src[i] != '\0'; i++)
		srclen++;

	/*append the source string to the destination*/
	for (i = 0; i <= srclen; i++)
		dest[destlen + i] = src[i];
	return (dest);
}

