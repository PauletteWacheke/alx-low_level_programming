#include <stdlib.h>
#include "main.h"
/**
 * alloc_grid - function that returns a pointer to a 2D array of integers.
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: NULL if width/height is 0 or -ve && NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **grid;

	if (width <= 0 || height <= 0)
		return (NULL);
	grid = (int **)malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}
	return (grid);
	free(grid);
}



