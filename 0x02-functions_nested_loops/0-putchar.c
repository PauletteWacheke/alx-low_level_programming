#include <stdio.h>
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
		putchar(string[i]);
		i++;
	}
	putchar('\n');

	return (0);
}
