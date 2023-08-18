#include "lists.h"

/**
 * dlistint_len - prints the number of items in the list
 * @h: pointer to each items
 *
 * Return: the number of items in the list
 */

size_t dlistint_len(const dlistint_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
