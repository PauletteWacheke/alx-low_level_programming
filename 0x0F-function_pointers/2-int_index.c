#include "function_pointers.h"
#include <stdlib.h>

/**
 * int_index - function that searches for an integer
 *
 * @size: number of elements in the array, array
 * @array: array of integer
 * @cmp: pointer to the function to be used to compare values
 *
 * Return: index of the 1st element or -1
 *
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
