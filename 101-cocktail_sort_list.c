#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the cocktail shaker sort algorithm. prints
 * the list after every swap.
 * @list: list of integer
 * Return: returns nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tail = *list; tail->next != NULL; tail = tail->next)
		;
	while (!shaken_not_stirred)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				ahead_swap_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				behind_swap_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}

/**
 * ahead_swap_node - swaps a node with the node infront of it
 * @list: pointer to head of list
 * @tail: pointer to tail of list
 * @shaker: pointer to current swapping node of cocktail algorithm
 * Return: returns nothing
 */
void ahead_swap_node(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp;

	temp = (*shaker)->next;
	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * behind_swap_node - swaps a node with the node before it
 * @list: pointer to head of list
 * @tail: pointer to tail of list
 * @shaker: pointer to current swapping node of cocktail algorithm
 * Return: returns nothing
 */
void behind_swap_node(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp;

	temp = (*shaker)->prev;
	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}
