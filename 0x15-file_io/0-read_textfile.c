#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
/**
 * read_textfile - function that reads a text file and prints it to the POSIX
 * standard output
 * @letters: number of letters it should read and print
 * @filename: the file name
 *
 * Return: actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file, rd;

	char *buffer;

	if (!filename)
		return (0);

	file = open(filename, O_RDONLY, 0600);

	if (file == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);

	rd = read(file, buffer, letters);
	write(STDOUT_FILENO, buffer, rd);
	free(buffer);
	close(file);
	return (rd);

}
