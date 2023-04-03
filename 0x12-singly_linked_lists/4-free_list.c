#include "lists.h"

/**
 * free_list - frees the memory allocated for a list
 */

void free_list(list_t *head)
{
	list_t *current_node;

	current_node = head;
	while (current_node != NULL)
	{
		list_t *next = current_node->next;
		free(current_node);
		current_node = next;
	}
}
