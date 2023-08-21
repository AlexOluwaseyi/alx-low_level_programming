#include "main.h"

/**
 * _strlen - Counts the length of a string
 * @s: The string to be counted
 *
 * Return: The length of the string (i)
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
