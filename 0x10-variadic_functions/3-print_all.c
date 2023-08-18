#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_all - function that prints anything
 *
 * @format: list of types of arguments passed to the function
 *
 */

void print_all(const char *const format, ...)
{
	va_list(ap);
	char c;
	int i;
	float f;
	char *s;

	int j = 0;

	va_start(ap, format);

	while (format[j] != '\0')
	{
		switch (format[j])
		{
			case 'c':
				c = (char)va_arg(ap, int);
				printf("%c", c);
				break;
			case 'i':
				i = va_arg(ap, int);
				printf("%d", i);
				break;
			case 'f':
				f = (float)va_arg(ap, double);
				printf("%f", f);
				break;
			case 's':
				s = va_arg(ap, char*);
				if (s == NULL)
					printf("(nil)");

				printf("%s", s);
				break;
		}
		j++;
		if (format[j] != '\0')
			printf(",");
	}
	va_end(ap);
	printf("\n");
}
