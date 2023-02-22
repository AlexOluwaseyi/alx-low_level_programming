#include <stdio.h>
#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @num: number passed to the print_last_digit function
 *
 * Return: Always 0.
 */
int print_last_digit(int num)
{
	int lastDigit;

	lastDigit = num % 10;
	if (lastDigit < 0)
		lastDigit *= -1;
	_putchar(lastDigit + '0');
	return (lastDigit);
}
