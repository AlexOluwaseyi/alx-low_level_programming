#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/**
 * init_dog - initialize a variable of type struct dog
 * @d: structure name
 * @name: name of dog
 * @age: Age of the dog
 * @owner: The owner of the dog
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	d = malloc(sizeof(struct dog));	
	d->name = name;
	d->age = age;
	d->owner = owner;
}
