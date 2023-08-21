#include <stdio.h>
#include "main.h"

/**
 * _abs - convert integer to its absolute value
 * @x: Number whose absolute is to be calculated
 * Return: Always 0.
 */
int _abs(int x)
{
	if (x >= 0)
		return (x);
	else if (x < 0)
		return (-x);
	return (0);
}
