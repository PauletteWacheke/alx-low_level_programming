#include <stdlib.h>
#include "main.h"
/**
 * free_grid - function that frees 2D grid prev created by alloc_grid function
 * @grid: pointer to the 2D grid
 * @height: height of the grid
 *
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;
	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
