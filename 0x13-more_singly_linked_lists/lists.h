#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/**
 * struct list - singly linked list
 * @str: string
 * @len: length of the string
 * @next: pointer to the next node
 *
 * Description: Singly linked list node structure
 */

typedef struct list
{
	int n;
	struct list *next;
} listint_t;

size_t print_listint(const listint_t *h);


#endif /* ifndef LISTS_H */
