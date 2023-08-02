#include "main.h"
/**
 * _print_rev_recursion - recursive function that prints a string in reverse
 * @s: string to be reversed
 *
 * Return: 0 on success
 */
void _print_rev_recursion(char *s)
{
	int i;
	char c;

	for (i = 0; s[i] != '\0'; i++)
	{
	}
	for (i = i - 1; i >= 0; i--)
	{
		c = s[i];
		_putchar(c);
	}
	_putchar('\0');
}
