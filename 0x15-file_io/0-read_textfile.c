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
	ssize_t myfile, sh, d;
	char *text;

	text = malloc(letters);
	if (text == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	myfile = open(filename, O_RDONLY);

	if (myfile == -1)
	{
		free(text);
		return (0);
	}

	sh  = read(myfile, text, letters);

	d = write(STDOUT_FILENO, text, sh);

	close(myfile);

	return (d);
}

