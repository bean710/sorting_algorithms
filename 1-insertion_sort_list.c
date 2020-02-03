#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly-linked list using the insertion-sort
 * algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *step, *back, *tmp;

	if (!list || !*list || !((*list)->next))
		return;

	step = *list;
	back = step;
	if (step)
		step = step->next;

	while (step)
	{
		back = step;
		while (back && back->prev && back->prev->n > step->n)
		{
			tmp = back->prev;
			if (tmp->prev)
				tmp->prev->next = back;
			else
				*list = back;
			if (back->next)
				back->next->prev = tmp;
			tmp->next = back->next;
			back->prev = tmp->prev;
			back->next = tmp;
			tmp->prev = back;

			 print_list(*list);
		}
		step = step->next;
	}
}
