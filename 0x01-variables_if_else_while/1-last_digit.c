#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/**
 * main - is the main function
 *
 * Return: 0 (success)
 */
int main(void)
{
	int n;
	int a;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	a = n % 9;
	if (n > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, a);
	}
	else if (n == 0)
	{
		printf("Last digit of %d is %d and is 0\n", n, a);
	}
	else if (n < 6)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, a);
	}
	return (0);
}
