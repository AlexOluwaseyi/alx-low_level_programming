#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @str: string
 * @len: length of the string
 * @next:pointer to the next node
 *
 * Description: Singly linked list node structure
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);


#endif /* #ifndef LIST_H */
