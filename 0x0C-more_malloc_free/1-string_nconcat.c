#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters to take from s2
 * Return: pointer to allocated memory
 * Or NULL if malloc fails
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *newString;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int i = 0;
	unsigned int x, y, sum;

	if (s1 == NULL)
		s1 = "";
	else
	{
		while (s1[len1] != '\0')
			len1++;
	}
	if (s2 == NULL)
		s2 = "";
	else
	{
		while (s2[len2] != '\0')
			len2++;
	}
	if (n < len2)
		len2 = n;
	sum = len1 + len2;
	newString = malloc(sum + 1);
	if (newString == NULL)
		return (NULL);
	for (x = 0; x < len1; x++)
		newString[x] = s1[x];
	for (y = len1; y < len1 + len2; y++)
	{
		newString[y] = s2[i];
		i++;
	}
	newString[x + y] = '\0';
	return (newString);
}
