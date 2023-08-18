#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts new node at index position
 * @h: pointer to first node in the list
 * @idx: index or position where new node is to be added
 * @n: new node to be added at index
 *
 * Return: new node
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *new_node;
	unsigned int i;

	if (!h)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->prev = NULL;
		new_node->next = *h;
		if (*h)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	current = *h;
	for (i = 0; i < idx - 1; i++)
	{
		if (!current)
		{
			free(new_node);
			return (NULL);
		}
		current = current->next;
	}
	if (!current)
	{
		free(new_node);
		return (NULL);
	}
	new_node->prev = current;
	new_node->next = current->next;
	if (current->next)
		current->next->prev = new_node;
	current->next = new_node;
	return (new_node);
}
