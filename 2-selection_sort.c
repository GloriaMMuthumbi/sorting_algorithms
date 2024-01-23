#include "sort.h"
/**
 * selction_sort - sorts an array of integers in ascending order using
 * the selction sort algorithm. prints the array after
 * each swap
 * @array: array of integers
 * @size: size of array
 * Return: returns nothing
 */
void selection_sort(int *array, size_t size)
{
	int *first;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		first = array + i;
		for (j = i+1; j < size; j++)
			first = (array[j] < *first) ? (array + j) : first;

		if ((array + i) != first)
		{
			swap_elems_selection(array + i, first);
			print_array(array, size);
		}
	}
}

/**
 * swap_elems_selection - swaps two integers in array
 * @elem1: first integer
 * @elem2: second integer
 * Return: returns nothing
 */
void swap_elems_selection(int *elem1, int *elem2)
{
	int temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}
