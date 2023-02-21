#include<stdio.h>
#include<stdlib.h>
/*
 * main - program prints out the alphabet using putchar
 *
 * Return 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
		putchar(i);
	putchar('\n');
	return (0);
}
