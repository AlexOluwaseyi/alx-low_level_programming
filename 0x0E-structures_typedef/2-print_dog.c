#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * print_dog - prints the dog struct
 * @d: the dog structure to be printed
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
		exit(1);
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else 
		printf("Name: %s\n", d->name);
	if (d->age == NAN)
		printf("Age: (nil)\n");
	else
		printf("Age: %.1f\n", d->age);
	if (d->owner ==NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}		
