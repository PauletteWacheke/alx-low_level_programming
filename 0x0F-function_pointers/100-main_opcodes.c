#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of itself
 * @argc: no of arguments
 * @argv: array of pointers to the arguments
 *
 * Return: Always 0
 *
 */

int main(int argc, char *argv[])
{
	int a, b;
	int (*address)(int, char **) = main;

	unsigned char opcode;

	if (argc != 2)
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

	for (b = 0; b < a; b++)
	{
		opcode = *(unsigned char *)address;
		printf("%.2x", opcode);

		if (b == a - 1)
			continue;
		printf(" ");

		address++;
	}

	printf("\n");
}


