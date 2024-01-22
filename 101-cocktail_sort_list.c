#include "sort.h"
/**
 * swap_nodes- Swaps nodes
 * @list: doubly linked list
 * @node1: node1
 * @node2: node2
 */

void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
/**
 * cocktail_shaker_sort_list - Sorts a doubly linked list in ascending order
 *                             using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped_node;
	listint_t *current, *last_backward, *last_forward;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (1)
	{
		swapped_node = 0;

		for (current = (*list); current->next != last_forward; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, current->next);
				print_list((const listint_t *)*list);
				swapped_node = 1;
			}
		}
		last_forward = current;

		if (!swapped_node)
			break;
		swapped_node = 0;

		for (current = current->prev; current->prev != last_backward; current = current->prev)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, current->next);
				print_list((const listint_t *)*list);
				swapped_node = 1;
			}
		}
		last_forward = current;

		if (!swapped_node)
			break;
		last_backward = current;
	}
}
