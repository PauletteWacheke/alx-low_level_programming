#include "main.h"

/**
 * append_text_to_file - function that appends text at end of file
 * @filename: file name
 * @text_content: NULL terminated string to add at end of file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file, r, len;

	if (filename == NULL)
		return (-1);
	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);
	if (!text_content)
		return (1);
	len = 0;
	while (text_content[len])
		len += 1;
	r = write(file, text_content, len);
	if (r == -1)
		return (-1);
	r = close(file);
	if (r == -1)
		return (-1);
	return (1);
}
