#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - returns sum of two numbers
 * @a: 1st integer
 * @b: 2nd integer
 *
 * Return: sum of a and b
 *
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - returns difference of two numbers
 * @a: 1st integer
 * @b: 2nd integer
 *
 * Return: differnce of a and b
 *
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - returns the product of two numbers
 * @a: 1st integer
 * @b: 2nd integer
 *
 * Return: product of a and b
 *
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - returns the division of two numbers
 * @a: 1st number
 * @b: 2nd number
 *
 * Return: dision result
 *
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - returns the modulus of two numbers
 * @a: 1st integer
 * @b: 2nd integer
 *
 * Return: the remainder of division of a and b
 *
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
