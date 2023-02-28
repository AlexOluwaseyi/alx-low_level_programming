#include "main.h"

/**
 * puts_half - prints the latter half of a string
 * @str: The original string.
 */

void puts_half(char *str)
{
	int i = 0;
	int len = 0;
	int j = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	j = len / 2;
	for (i = j; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
