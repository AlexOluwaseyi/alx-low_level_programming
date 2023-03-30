#include "lists.h"

/**
 * list_len - cunts the number of elements in a linked list
 * @h: the list
 * Return: the number of elements
 */

size_t list_len(const list_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
