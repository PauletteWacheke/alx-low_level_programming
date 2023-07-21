#include "main.h"
/**
 * more_numbers - prints the numbers 0 to 14,  10 times
 *
 */
void more_numbers(void)
{
	int l, c;

	for (l = 0; l < 10; l++)
	{
		for (c = 0; c <= 14; c++)
		{
			if (c > 9)
				_putchar((c / 10) + '0');
			_putchar((c % 10) + '0');
		}
		_putchar('\n');
	}
}
