#include "lists.h"

/**
 * print_dlistint - prints the nodes in a list
 * @h: nodes in the list to be printed
 *
 * Return: number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}
