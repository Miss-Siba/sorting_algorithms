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
 * insertion_sort_list- sorts a doubly linked list in ascending order.
 * @list: doubly linked listed
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *present, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (present = (*list)->next; present != NULL; present = temp)
	{
		temp = present->next;
		insert = present->prev;
		while (insert != NULL && present->n < insert->n)
		{
			swap_nodes(list, &insert, present);
			print_list((const listint_t *)*list);
		}
	}
}
