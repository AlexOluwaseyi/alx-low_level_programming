#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * print_dog - prints the dog struct
 * @d: the dog structure to be printed
 * Return: nothing if d == NULL
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
	{
	}
	else
	{
		printf("Name: %s\n", d->name ? d->name : "(nil)");
		printf("Age: %.1f\n", d->age);
		printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
	}
}
