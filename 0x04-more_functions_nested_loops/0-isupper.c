#include <stdio.h>
#include "main.h"

/**
 * _isupper - check for UPPERCASE characters
 * @c: characters checked for case.
 * Return: 1 if UPPERCASE and 0 if not
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	
	return(0);
}
