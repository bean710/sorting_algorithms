#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *step, *next_step, *bt;

	step = *list;
	if (step)
		step = step->next;

	while (step)
	{
		next_step = step->next;
		bt = step->prev;

		if (step->n < bt->n)
		{
			while (bt->prev && bt->prev->n > step->n)
				bt = bt->prev;

			if (next_step)
				next_step->prev = step->prev;

			step->prev->next = step->next;

			if (bt->prev)
				bt->prev->next = step;
			else
				*list = step;

			step->prev = bt->prev;
			step->next = bt;
			bt->prev = step;

			print_list(*list);
		}

		step = next_step;	
	}
}
