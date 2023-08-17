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
	int i = 0;

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] == 'c')
		{
			char c = (char)va_arg(ap, int);

			printf("%c", c);
		}
		else if (format[i] == 'i')
		{
			int num = va_arg(ap, int);

			printf("%d", num);
		}
		else if (format[i] == 'f')
		{
			double f = va_arg(ap, double);

			printf("%f", f);
		}
		else if (format[i] == 's')
		{
			char *s = va_arg(ap, char*);

			if (s == NULL)
				printf("(nil)");
			else
				printf("%s", s);
		}
		i++;
		if (format[i] != '\0')
			printf(",");
	}
	va_end(ap);
	printf("\n");
}
