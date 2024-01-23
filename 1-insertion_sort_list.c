#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using insertion sort algorithm. prints
 * the list after every swap
 * @list: list to be sorted
 * Return: returns nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterator = (*list)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		insert = iterator->prev;
		while (insert != NULL && iterator->n < insert->n)
		{
			swap_elems_nodes(list, &insert, iterator);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_elems_nodes - swaps two nodes in a doubly linked list
 * @head: pointer to pointer to the head of list
 * @node1: first node
 * @node2: second node
 * Return: returns nothing
 */
void swap_elems_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
