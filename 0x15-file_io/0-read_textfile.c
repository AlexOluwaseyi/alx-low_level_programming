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
	char *buffer;
	FILE *fp;
	ssize_t bytes_read;
	ssize_t bytes_written;

	if (filename == NULL)
		return (0);

	fp = fopen(filename, "r");
	if (fp == NULL)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
		return (0);

	bytes_read = fread(buffer, sizeof(char), letters, fp);
	if (bytes_read < 0)
	{
		fclose(fp);
		return (0);
	}
	buffer[bytes_read] = '\0';

	bytes_written = fwrite(buffer, sizeof(char), bytes_read, stdout);
	free(buffer);
	fclose(fp);

	if (bytes_written != bytes_read)
		return (0);
	return (bytes_read);
}
