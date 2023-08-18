#include <stdio.h>
#include <stdlib.h>

/**
 * main - function to print its own opcode
 * @argc: number of arguments
 * @argv: argumrnt variables passed
 *
 * Return: 0 on success
 *
 */

int main(int argc, char **argv)
{
	int a, b;
	char *s;

	if (argc < 2)
	{
		printf("Error\n");
		exit(1);
	}
	a = atoi(argv[1]);
	if (a < 0)
	{
		printf("Error\n");
		exit(2);
	}
	s = (char *)main;
	for (b = 0; b < a; b++)
		printf("%02hhx ", s[b]);
	printf("%02hhx\n", s[b]);
	return (0);
}
