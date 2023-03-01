#include "main.h"

/**
 * _strncpy - copies a string to a destination
 * @dest: desination string
 * @src: source string
 * @n: maximum number of bytes to by copies from source to destination
 * Return: destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i< n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
