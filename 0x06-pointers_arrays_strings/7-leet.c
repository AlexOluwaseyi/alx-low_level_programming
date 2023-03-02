#include "main.h"

/**
 * leet - encode strings into 1337 (Leet Speak)
 * @s: String to be encoded.
 * Return: Encoded string
 */

char *leet(char *s)
{
	char codec[] = "aAeEoOtTlL";
	char leet[] = "4433007711";
	int i = 0;
	int j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; codec[j] != '\0'; j++)
		{
			if (s[i] == codec[j])
			{
				s[i] = leet[j];
			}
		}
	}
	return (s);
}
