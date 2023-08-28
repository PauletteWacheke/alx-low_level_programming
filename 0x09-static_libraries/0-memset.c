#include "main.h"
/**
 * _memset - function that fills memory with a constant byte
 * @s: char , pointer to the memory area where the filling will start
 * @b: char , constant byte to be copied..
 * @n: int , number of bytes to fill with the constant value
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
