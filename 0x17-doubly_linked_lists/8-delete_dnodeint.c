#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index
 * @head: pointer to first node in the list
 * @index: pointer node to be deleted.
 *
 * Return: On success - 1 and 0 on failure.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current;

	if (!head || !*head)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	for (i = 0; i < index; i++)
	{
		if (!current)
			return (-1);
		current = current->next;
	}

	if (!current)
		return (-1);

	if (current->prev)
	{
		current->prev->next = current->next;
	}
	if (current->next)
	{
		current->next->prev = current->prev;
	}

	free(current);
	return (1);
}
