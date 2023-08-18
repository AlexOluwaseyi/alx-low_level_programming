#include "lists.h"

/**
 * free_dlistint - frees a list
 * @head: pointer to the first node in the list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next;
		free(current_node);
	}
	free(head);
}
