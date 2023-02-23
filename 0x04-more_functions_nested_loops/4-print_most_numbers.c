#include "main.h"

/**
 * print_most_numbers - checks for checks for a digit (0 through 9).
 *
 * Return: Always 0.
 */
void print_most_numbers(void)
{
int c;

for (c = 0; c <= 9; c++)
{
if (c != 2)
{
if (c != 4)
{
_putchar(c + '0');
}
}
}
_putchar('\n');
}
