#include<stdio.h>
#include "main.h"
/*
 * print_alphabet - prints out the alphabets
 *
 * Return: void
 */
void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
		_putchar(i);
	putchar('\n');
}
