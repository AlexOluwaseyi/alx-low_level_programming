#include "main.h"

/**
 * create_array - Creates an array of characters
 * @size: size of the arrays
 * @char: the array of character(s)
 * Return: NULL if size is 0
 * Or a pointer to the array.
 */

char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	str = malloc(sizeof(char) * size);
	if (size == 0 || str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		str[i] = c;
	}
	return (str);
}
