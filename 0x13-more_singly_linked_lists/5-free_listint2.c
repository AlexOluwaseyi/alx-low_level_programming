#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head: pointer to pointer to head node of list.
 */

void free_listint2(listint_t **head)
{
	listint_t *current;
	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
}
