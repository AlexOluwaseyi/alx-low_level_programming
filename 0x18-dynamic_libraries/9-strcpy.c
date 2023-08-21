#include "main.h"

/**
 * _strcpy - copy content from source to destination
 * @dest: destination file
 * @src: source file
 *
 * Return: Pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0;
	int i = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
	return (dest);
}
