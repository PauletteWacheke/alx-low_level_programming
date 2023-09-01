#include "main.h"

/**
 * get_endianness - function that checks the endianness
 *
 * Return: 0 if system is big-endian, 1 if the system is little endian
 *
 */

int get_endianness(void)
{
	int num = 1;
	char *endian = (char *)&num;

	if (*endian == 1)
		return (1);

	return (0);
}
