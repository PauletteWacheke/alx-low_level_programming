#include "main.h"
/**
 * _sqrt_recursion - function that returns the natural
 * square root of a number.
 *
 * @n: integer
 * Return: integer
 */
int _sqrt_recursion(int n)
{
	return (natural_square(n, 1));
}

/**
 * natural_square - a function that helps find the natural square
 * @x: integer
 * @y: integer
 *
 * Return: squareroot or -1
 */

int natural_square(int x, int y)
{
	int s = y * y;

	if (s > x)
		return (-1);
	if (s == x)
		return (y);
	return (natural_square(x, y + 1));
}
