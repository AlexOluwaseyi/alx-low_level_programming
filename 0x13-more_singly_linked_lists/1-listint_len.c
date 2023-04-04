#include "lists.h"

/**
 * listint_len - ments of a listint_t list
 * @h: pointer to the head to the list
 *
 * Return: The number of nodes in the list
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
        }
	return (count);
}
