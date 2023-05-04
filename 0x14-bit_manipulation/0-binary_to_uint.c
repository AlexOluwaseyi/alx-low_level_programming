#include "main.h"

/**
 * binary_to_uint - converts binary number to unsigned in
 * @b: pointer to the binary number
 * Return: the converted unsigned int
 * Or 0 if char is not 0 or 1 or if char is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	int length = 0;
	int decimal = 0;

	if (b == NULL)
		return (0);

	length = strlen(b);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (!isdigit(b[i]) || (b[i] != '0' && b[i] != '1'))
			return (0);
	}
	for (i = 0; i < length; i++)
	{
		decimal = (decimal << 1) | (b[i] - '0');
	}
	return (decimal);
}
