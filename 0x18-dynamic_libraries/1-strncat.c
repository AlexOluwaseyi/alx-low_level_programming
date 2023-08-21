#include "main.h"

/**
 * _strncat - Concatenates strings
 * @dest: destination string
 * @src: source string
 * @n: Max bytes
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int srclen = 0;
	int destlen = 0;
	int i = 0;
	int j = 0;

	while (src[srclen] != '\0')
	{
		srclen++;
	}
	while (dest[destlen] != '\0')
	{
		destlen++;
	}
	for (i = destlen; (i < (destlen + n) && j < srclen); i++)
	{
		dest[i] = src[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
