#include <stdio.h>
/**
 * main - program that prints the number of arguments passed into it
 * @argc: size of argv
 * @argv: array
 *
 * Return: 0 on success
 */
int main(int argc, char **argv __attribute__((unused)))
{
	if (argc > 0)
		printf("%d\n", argc - 1);
	return (0);
}
