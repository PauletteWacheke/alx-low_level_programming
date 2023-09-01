#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would need to flip
 * to get from one number to another
 * @n: the number
 * @m: number to flip n to
 *
 * Return: necessary number of bits to flip to get from n to m
 *
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result > 0)
	{
		if (xor_result & 1)
			count++;
		xor_result >>= 1;
	}

	return (count);
}
