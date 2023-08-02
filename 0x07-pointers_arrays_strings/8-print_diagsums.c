#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - function that prints the sum of two
 * diagonls of a square matrix of integers
 * @a: array
 * @size: size of array
 */
void print_diagsums(int *a, int size)
{
	int i, j;
	int sum0 = 0;
	int sum1 = 1;

	for (i = 0; i < size * size; i += (size + 1))
	{
		sum0 += a[i];
	}
	for (j = size - 1; j < size * size - (size - 1); j += (size - 1))
	{
		sum1 += a[j];
	}
	printf("%d, %d\n", sum0, sum1);
}
