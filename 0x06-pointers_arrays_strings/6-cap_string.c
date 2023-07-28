#include "main.h"
/**
 * cap_string - function that capitalizes all words of a string
 * @str - string to be capitralized
 *
 * Return: pointer to the changed string
 */
char *cap_string(char *)
{
	int i = 0;
	int capitalize_next = 1;

	while (str[i] != '\0')
	{
		if (isspace(str[i]) || str[i] == ',' || str[i] == ';' || str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == '"' || str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}')
		{
			capitalize_next = 1;
		}
		else if (capitalize_next)
		{
			str[i] = toupper(str[i]);
			capitalize_next = 0;
		}
		else
		{
			str[i] = tolower(str[i]);
		}
		i++;
	}
	return str;
}

