#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */

void rev_string(char *s)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	k = len / 2;
	for (i = 0; i < k; i++)
	{
		j = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = j;
	}
}
