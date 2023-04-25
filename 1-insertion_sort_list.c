#include "sort.h"

/**
 * insertion_sort_list - function that sorts the insertion sort algorithm
 * @list: doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *mark;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	mark = (*list)->next;
	while (mark != NULL)
	{
		while (mark->prev != NULL && mark->n < mark->prev->n)
		{
			mark->prev->next = mark->next;
			if (mark->next != NULL)
				mark->next->prev = mark->prev;
			mark->next = mark->prev;
			mark->prev = mark->prev->prev;
			mark->next->prev = mark;
			if (mark->prev == NULL)
				*list = mark;
			else
				mark->prev->next = mark;
			print_list(*list);
		}
		mark = mark->next;
	}
}
