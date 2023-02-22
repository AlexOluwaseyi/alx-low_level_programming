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

	if (num >= 0)
	{
		lastDigit = num % 10;
		return (lastDigit);
	}
	else
	{
		lastDigit = (-num) % 10;
		return (lastDigit);
	}
	return (0);
}
