#include "main.h"
/**
 * main - Prints _putchar
 *
 * Return: 0 on success
 */
int main(void)
{
	char string[] = "_putchar";
	int i = 0;

	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}
