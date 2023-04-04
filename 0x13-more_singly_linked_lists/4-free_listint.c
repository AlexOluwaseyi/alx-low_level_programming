#include "lists.h"

/**
 * free_listint - free memory allocated to list
 * @head: pointer to first address in list to be freed
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
