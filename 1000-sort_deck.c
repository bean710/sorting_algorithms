#include "deck.h"
#include <stdlib.h>

/**
 * sort_deck - sorts a doubly linked list of card structs
 * @deck: pointer the the head of the doubly linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *D[52];
	to_array(*deck, D);
	from_array(deck, D);
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
			array[i]->next = array[i + 1];
		}
		if (i < 51 && i != 0)
		{
			array[i]->next = array[i + 1];
			array[i]->prev = array[i - 1];
		}
		if (i == 51)
		{
			array[i]->prev = array[i - 1];
			array[i]->next = NULL;
		}
	}
}

int get_val(const card_t *card)
{
	char vals[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1',
		'J', 'Q', 'K'};
	size_t i;
	int v = 0;

	for (i = 0; i < 13; ++i)
	{
		if (vals[i] == card->value[0])
		{
			v = i;
			break;
		}
	}

	return (v + card->kind * 13);
}

void to_array(deck_node_t *deck, deck_node_t **D)
{
	deck_node_t *node;

	for (node = deck; node; node = node->next)
		D[get_val(node->card)] = node;
}
