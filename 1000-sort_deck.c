#include "deck.h"
#include <stdlib.h>

/**
 *
 */
void sort_deck(deck_node_t **deck)
{

}

void from_array(deck_node_t **head, deck_node_t **array)
{
	int i;

	for (i = 0; i < 52; i++)
	{
		if (i == 0)
		{
			*head = array[i];
			array[i]->prev = NULL;
		}
		if (i < 51 && i != 0)
		{
			array[i]->next = array[i + 1];
			array[i]->prev = array[i - 1];
		}
		if (i == 51)
		{
			array->prev = array[i - 1];
			array->next = NULL;
		}
	}
}
