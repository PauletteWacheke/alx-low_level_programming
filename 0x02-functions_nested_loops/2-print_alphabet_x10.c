#include "main.h"
/**
 * print_alphabet_x10 - prints the alphabet in lowercase 10 times
 *
 */
void print_alphabet_x10(void)
{
	int count = 0;
	char c = 'a';

	while (count <= 10)
	{
		for (c = 'a'; c <= 'z'; c++)
		{
			_putchar(c);
		}
		_putchar('\n');
		count++;
	}
}