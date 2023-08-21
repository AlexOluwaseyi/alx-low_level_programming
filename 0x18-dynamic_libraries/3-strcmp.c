#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: difference in s1 and s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int diff = 0;

	if (s1 == s2)
	{
		return (0);
	}
	else
	{
		while (s1[i] == s2[i])
		{
			i++;
		}
		diff = s1[i] - s2[i];
	}
	return (diff);
}
