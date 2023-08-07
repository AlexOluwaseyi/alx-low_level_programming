#include "main.h"

/**
 * read_textfile - REads text file and prints it to stdout
 * @filename: pointer to text file
 * @letters: Number of characters to print from the text file
 *
 * Return: Number of letter read and printed
 * Or 0 if file could not be openeed or read, if filename is NULL
 * Or if write fails
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrd = read(fd, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(fd);

	free(buf);

	return (nwr);
}
