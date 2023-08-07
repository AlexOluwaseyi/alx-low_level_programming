#include "main.h"

/**
 * append_text_to_file - creates a file with read&write permissions
 * @filename: pointer to file to create/read from
 * @text_content: content to be read or write to file
 *
 * Return: 1 on success.
 * Or -1 on failure or if filename is NULL
 */

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *fp;

	if (filename == NULL)
		return (-1);
	fp = fopen(filename, "a+");
	if (fp == NULL)
		return (-1);
	if (text_content != NULL)
		fwrite(text_content, sizeof(char), strlen(text_content), fp);
	fclose(fp);
	return (1);
}
