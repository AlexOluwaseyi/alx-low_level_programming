#include "lists.h"

/**
 * add_dnodeint - adds a new node at the head of a list
 * @head: pointer to the beginning of the node
 * @n: item to be added to the head of the list
 *
 * Return: new_node
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;

	return (new_node);
}
