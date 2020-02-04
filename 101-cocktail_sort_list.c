#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - sorts linked list of integers in ascending order with
 * a bubble sort-like algotrithm called cocktail sort
 * @list: Double pointer to the doubly-linked list head
 */
void cocktail_sort_list(listint_t **list)
{
	int did_swap = 0;
	listint_t *node;

	if (!list || !*list || !(*list)->next)
		return;

	node = *list;

	do {
		while (node->next)
		{
			if (node->next->n < node->n)
			{
				swap_forward(node, list);
				did_swap = 1;
				print_list(*list);
			}
			else
				node = node->next;
		}

		if (!did_swap)
			return;

		did_swap = 0;

		while (node->prev)
		{
			if (node->prev->n > node->n)
			{
				swap_backward(node, list);
				did_swap = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	} while (did_swap);
}

/**
 * swap_forward - Swaps a node with the one directly "next" to it
 * @node: The "left" node to swap
 * @list: Double pointer to the head of the list
 */
void swap_forward(listint_t *node, listint_t **list)
{
	listint_t *swap = node->next;

	if (node->prev)
		node->prev->next = swap;
	else
		*list = swap;

	if (swap->next)
		swap->next->prev = node;

	swap->prev = node->prev;
	node->next = swap->next;
	node->prev = swap;
	swap->next = node;
}

/**
 * swap_backward - Swaps a node with the one directly "prev" to it
 * @node: The "right" node to swap
 * @list: Double pointer to the head of the list
 */
void swap_backward(listint_t *node, listint_t **list)
{
	listint_t *swap = node->prev;

	if (node->next)
		node->next->prev = swap;

	if (swap->prev)
		swap->prev->next = node;
	else
		*list = node;

	swap->next = node->next;
	node->prev = swap->prev;
	node->next = swap;
	swap->prev = node;
}
