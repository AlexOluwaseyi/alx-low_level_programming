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
	dlistint_t *new_node, *temp_node;

	unsigned int i;

	if (h == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *h;
		*h = new_node;
		return (new_node);
	}
	temp_node = *h;
	for (i = 0; i < idx - 1 && temp_node != NULL; i++)
		temp_node = temp_node->next;
	if (temp_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = temp_node->next;
	temp_node->next = new_node;
	return (new_node);
}
