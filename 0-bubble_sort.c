#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using Bubble sort algorithm. prints the array
 * after every swap of elements
 * @array: array of integers
 * @size: size of te array
 * Return: returns nothing
 */
void bubble_sort(int *array, size_t size)
{
	bool sorted = false;
	size_t i, len;

	len = size;
	if (array == NULL || size < 2)
		return;

	while (sorted == false)
	{
		sorted = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_elems(array + i, array + i + 1);
				print_array(array, size);
				sorted = false;
			}
		}
		len--;
	}

}

/**
 * swap_elems - swaps two adjacent elements of the array
 * @elem1: first element
 * @elem2: second element
 * Return: returns nothing
 */
void swap_elems(int *elem1, int *elem2)
{
	int temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}
