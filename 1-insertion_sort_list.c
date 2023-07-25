#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: double pointer to the dlinked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *previous;
	listint_t *current = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current)
	{
		if (current->prev && current->prev->n > current->n)
		{
			temp = current;
			previous = current->prev;

			/* Swap the nodes */
			if (temp->next != NULL)
				temp->next->prev = previous;

			if (previous->prev != NULL)
				previous->prev->next = temp;
			else
				*list = temp;

			temp->prev = previous->prev;
			previous->prev = temp;
			previous->next = temp->next;
			temp->next = previous;

			/* Move pointer back for the next iteration */
			current = *list;
			print_list(*list);
			continue;
		}
		current = current->next;
	}
}
