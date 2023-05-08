#include "main.h"

/**
 * create_file - creates a file with read&write permissions
 * @filename: pointer to file to create/read from
 * @text_content: content to be read or write to file
 *
 * Return: 1 on success. -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int i = 0, fd;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	/* Count the number of characters in the text */
	while (text_content[i] != '\0')
		i++;

	/* Create or truncate the file and open it for writing */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* Write the text to the file */
	if (write(fd, text_content, i) != i)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
