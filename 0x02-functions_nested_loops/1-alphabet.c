#include<stdio.h>
#include "main.h"
/*
 * main - program prints out the alphabet using _putchar
 * _putchar defined in main.h
 *
 * Return: 0 (Success)
 */
void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
		_putchar(i);
	putchar('\n');
}
