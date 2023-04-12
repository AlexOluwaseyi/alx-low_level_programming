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
	FILE *fp;

	if (filename == NULL)
		return (-1);
	fp = fopen(filename, "w+");
	if (fp == NULL)
		return (-1);
	if (text_content != NULL)
		fwrite(text_content, sizeof(char), strlen(text_content), fp);
	fclose(fp);
	return (1);
}
