#include "main.h"

/**
 * string_toupper - Convert lowercase characters to uppercase
 * @n: string with lowercase characters
 *
 * Return: n
 */

char *string_toupper(char *n)
{
	int i = 0;

	while (n[i] != '\0')
	{
		if (n[i] >= 'a' && n[i] <= 'z')
		{
			n[i] = (n[i] - 'a') + 'A';
		}
		i++;
	}
	return (n);
}
