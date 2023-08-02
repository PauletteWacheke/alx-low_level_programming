#include "main.h"
/**
 * _memset - function that fills memory with a constant byte
 * @s: pointer to the memory area where the filling will start
 * @b: constant byte that will be copied to each byte of the memory area.
 * @n: number of bytes to fill with the constant value
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int n;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
