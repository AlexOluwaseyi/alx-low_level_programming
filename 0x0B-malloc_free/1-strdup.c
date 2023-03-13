#include "main.h"

/**
 * _strdup - Copies a string to a pointer
 * @str: string to be copied to pointer
 *
 * Return: NULL if str = NULL or insufficient memory
 * On success, rturns a pointer to duplicated string
 */

char *_strdup(char *str)
{
	int i;
	int len = 0;
	char *dupl;

	for (i = 0; str[i] != '\0'; i++)
	{
		len++;
	}
	dupl = malloc(sizeof(char) * len);
	if (str == NULL || dupl == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		dupl[i] = str[i];
	}
	return (dupl);
}
