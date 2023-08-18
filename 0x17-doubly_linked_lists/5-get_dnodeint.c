#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to head node of list.
 * @index: index of the node to return.
 *
 * Return: pointer to the nth node of the list, or NULL if it does not exist.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int i;

	for (i = 0; current != NULL && i < index; i++)
		current = current->next;
	return (current);
}
