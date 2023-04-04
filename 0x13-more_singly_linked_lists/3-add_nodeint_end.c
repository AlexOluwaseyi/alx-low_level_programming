#include "lists.h"

/**
 * add_nodeint_end - add a new node to the end of a linked list
 * @head: a pointer to a pointer to the first node in the list
 * @n: the value to be stored in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */

listint_t *add_nodeint_end(listint_t **head, int n)
{
	listint_t *new_node, *last_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	last_node = *head;
	while (last_node->next != NULL)
		last_node = last_node->next;

	last_node->next = new_node;
	return (new_node);
}
