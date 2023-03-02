#include "main.h"

/**
 * rot13 - encodes strings in the ROT13 encoding
 * @s: string to be encoded
 *
 * Return: encoded string
 */

char *rot13(char *s)
{
	char codec[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char ROT13[] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";
	int i = 0;
	int j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; codec[j] != '\0'; j++)
		{
			if (s[i] == codec[j])
			{
				s[i] = ROT13[j];
				break;
			}
		}
	}
	return (s);
}
