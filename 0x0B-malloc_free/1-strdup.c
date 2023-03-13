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
	int i, r;
	int len = 0;
	char *dupl;

	if (str == NULL)
        {
                return (NULL);
        }
	for (i = 0; str[i] != '\0'; i++)
	{
		len++;
	}
	dupl = malloc(sizeof(char) * (len + 1));
	if (dupl == NULL)
	{
		return (NULL);
	}
	for (r = 0; r < len + 1; r++)
	{
		dupl[r] = str[r];
	}
	return (dupl);
}
