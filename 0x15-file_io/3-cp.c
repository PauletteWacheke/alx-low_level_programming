#include "main.h"

/**
 * main - function that copies the contents of a file to another file
 * @argc: number of arguments
 * @argv: pointer point to the array of arguments
 *
 * Return: always 0
 * Description: if the argument count is incorrect, exit code 97
 *		if file_form does not exit or cannot be read, exit code 98
 *		if file_to cannot be created or written to, exit code 99
 *		if file_yo or file_from cannot be closed, exit code 100
 */

int main(int argc, char **argv)
{
	char *buffer;
	int to, from, res0, res1;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	res0 = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || res0 == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		res1 = write(to, buffer, res0);
		if (to == -1 || res1 == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		res0 = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (res0 > 0);

	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}

/**
 * create_buffer - function that allocates 1024bytes for a buffer
 * @file: file used to store
 *
 * Return: pointer to the new buffer
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (!buffer)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - function that closes the file descriptor
 * @fd: file descriptor to be closed
 *
 * Return: nothing(void)
 */

void close_file(int fd)
{
	int c;

	c = close(fd);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}


