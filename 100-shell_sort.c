#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * using Shell Sort algorithm, with Knuth sequence. prints the
 * array after each swap
 * @array: array of integers
 * @size: size of array
 * Return: returns nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (size < 2 || array == NULL)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_elems_shell(&array[j], &array[j - gap]);
				j -= gap;
			}
		}
		print_array(array, size);
	}
}

/**
 * swap_elems_shell - swaps two integers
 * @elem1: first interger
 * @elem2: second integer
 * Return: returns nothing
 */
void swap_elems_shell(int *elem1, int *elem2)
{
	int temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}
