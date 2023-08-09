#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - program that adds positive numbers
 * @argc: number of arguments
 * @argv: array
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	int i, j = 0, sum = 0, num;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		char *numstr = argv[i];

		while (numstr[j] != '\0')
		{
			if (!isdigit(numstr[j]))
			{
				printf("Error\n");
				return (1);
			}
			++j;
		}
		num = atoi(numstr);
		sum += num;
	}
	printf("%d\n", sum);
	return (0);
}
