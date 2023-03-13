#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer to new string
 * Or NULL if failled.
 */

char *str_concat(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int r = 0;
	int x = 0;
	char *newString;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;

	newString = malloc((sizeof(char) * i) + (sizeof(char) * (j + 1)));
	if (newString == NULL)
		return (NULL);
	for (r = 0; r < i; r++)
	{
		newString[r] = s1[r];
	}
	for (r = i; r < i + j; r++)
	{
		newString[r] = s2[x];
		x++;
	}
	return (newString);
}
