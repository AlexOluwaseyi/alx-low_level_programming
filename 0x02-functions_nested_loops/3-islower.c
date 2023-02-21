#include <stdio.h>
#include "main.h"

/**
 * _islower - checks for lowercase character
 * @c: character parameter for _islower
 *
 * Return: Always 0 (Success)
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
