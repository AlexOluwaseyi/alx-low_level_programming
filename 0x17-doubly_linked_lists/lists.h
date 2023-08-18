#ifndef LISTS_H
#define LISTS_H

/* Standard Functions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct list - singly linked list
 * @n: string
 * @next: pointer to the next node
 * @prev: pointer to the previous node
 *
 * Description: Singly linked list node structure
 */

typedef struct list
{
	int n;
	struct list *next;
	struct list *prev;
} dlistint_t;


/* Function Prototypes */
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);


#endif /* #ifndef LIST_H */
