#include "main.h"

/**
 * _strcat - Concatenates strings
 * @dest: destination string
 * @src: source string
 * Return: ptr
 */

char *_strcat(char *dest, char *src)
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
	for (i = destlen; i < destlen + srclen; i++)
	{
		dest[i] = src[j];
		j++;
	}
	return (dest);
}
