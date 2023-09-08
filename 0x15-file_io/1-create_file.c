#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: the filename
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file;
	int len, r;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file == -1)
		return (-1);

	if (!text_content)
		return (1);
	len = 0;

	while (text_content[len] != '\0')
		len += 1;

	r = write(file, text_content, len);
	if (r != len)
		return (-1);
	r = close(file);
	if (r == -1)
		exit(-1);

	return (1);
}


