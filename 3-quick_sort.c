#include "sort.h"
/**
 * quick_sort - sorts an array of integrs in ascending order using the
 * Quick Sort algorithm. prints the array after each swap
 * @array: array of integers
 * @size: size of array
 * Return: returns nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sorting(array, size, 0, size - 1);
}

/**
 * lomuto_partitioning - sorts a subset of an array accoridng to
 * partition scheme
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of subset
 * @right: last index of subset
 * Return: returns the last partition index
 */
int lomuto_partitioning(int *array, size_t size, int left, int right)
{
	int *piv, abv, bel;

	piv = array + right;
	for (abv = bel = left; bel < right; bel++)
	{
		if (array[bel] < *piv)
		{
			if (abv < bel)
			{
				swap_elems_quick(array + bel, array + abv);
				print_array(array, size);
			}
			abv++;
		}
	}
	if (array[abv] > *piv)
	{
		swap_elems_quick(array + abv, piv);
		print_array(array, size);
	}
	return (abv);
}

/**
 * swap_elems_quick - swaps two integers in array
 * @elem1: first integer
 * @elem2: second integer
 * Return: return nothing
 */
void swap_elems_quick(int *elem1, int *elem2)
{
	int temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

/**
 * lomuto_sorting - implements algorithm using recursion
 * @array: array of integers
 * @size: size of array
 * @left: start index of partition array
 * @right: last index of partition array
 */
void lomuto_sorting(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partitioning(array, size, left, right);
		lomuto_sorting(array, size, left, partition - 1);
		lomuto_sorting(array, size, partition + 1, right);
	}
}
