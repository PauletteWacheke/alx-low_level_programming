#include "main.h"
#include <stdio.h>
#include <ctype.h>
/**
 * cap_string - function that capitalizes all words of a string
 * @str - string to be capitalized
 *
 * Return: pointer to the changed string
 */
char *cap_string(char *str)
{
	int capitalize_next = 1;
		char *ptr = str;

		while (*ptr)
		{
			if(isspace(*ptr) || ispunct(*ptr))
			{
				capitalize_next = 1;
			}
			else if (capitalize_next)
			{
				*ptr = toupper(*ptr);
				capitalize_next = 0;
			}
			else 
			{
				*ptr = tolower(*ptr);
			}
			ptr++;
		}
		return (str);
}

