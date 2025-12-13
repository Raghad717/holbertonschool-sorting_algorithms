#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			prev_node = temp->prev;

			/* Swap temp and prev_node */
			if (prev_node->prev != NULL)
				prev_node->prev->next = temp;
			else
				*list = temp;

			if (temp->next != NULL)
				temp->next->prev = prev_node;

			prev_node->next = temp->next;
			temp->prev = prev_node->prev;

			temp->next = prev_node;
			prev_node->prev = temp;

			/* Print list after swap */
			print_list(*list);
		}
	}
}
