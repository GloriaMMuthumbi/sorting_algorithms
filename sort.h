#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool - Enumeration of boolean values
 *
 * @false: represents value false representing 0
 * @true: represents value true representing 1
 */

typedef enum bool
{
	false = 0,
	true
} bool;


/*PROTOTYPES*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void swap_elems(int *elem1, int *elem2);
void bubble_sort(int *array, size_t size);
void swap_elems_nodes(listint_t **head, listint_t **node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void swap_elems_selection(int *elem1, int *elem2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap_elems_quick(int *elem1, int *elem2);
int lomuto_partitioning(int *array, size_t size, int left, int right);
void lomuto_sorting(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
void swap_elems_shell(int *elem1, int *elem2);
void shell_sort(int *array, size_t size);
void ahead_swap_node(listint_t **list, listint_t **tail, listint_t **shaker);
void behind_swap_node(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);


#endif
