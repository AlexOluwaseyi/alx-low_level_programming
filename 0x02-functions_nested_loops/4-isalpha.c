#include <stdio.h>
#include "main.h"

/**
 * _isalpha - checks for lower and upper case alphabet
 * @c: is the argument for the function
 *
 * Return: Always 0 (success).
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
