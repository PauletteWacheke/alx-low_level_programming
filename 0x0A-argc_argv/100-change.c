#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the min no of coins to make chnage for an amount of money
 * @argc: number of arguments
 * @argv: array
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	int cents;
	int coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	while (cents > 0)
	{
		if (cents >= 25)
			coins += cents / 25;
			cents %= 25;
		else if (cents >= 10)
			coins += cents / 10;
			cents %= 10;
		else if (cents >= 5)
			coins += cents / 5;
			cents %= 5;
		else if (cents >= 2)
			coins += cents / 2;
			cents %= 2;
		else
			coins += cents;
			cents = 0;
	}

	printf("%d\n", coins);
	return (0);
}

