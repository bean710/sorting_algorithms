#include "sort.h"

/**
 * heap_sort - sorts an int array in ascending order
 * @array: the array to be sorted
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	unsigned int i, temp;

	for (i = size; i > 0; i++)
	{
		heapify(array, i, size);
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}

/**
 * heapify - arranges an array in a sift-down heap sort manner
 * @arr: the array to be sosrted.
 * @size: the size of the array (the part to be sorted)
 * @total: the total original array for printing
 */
void heapify(int *arr, unsigned int size, size_t total)
{
	int par, l_kid, r_kid;
	int tmp;

	par = (size - 2) / 2;

	while (par >= 0)
	{
		l_kid = 2 * par + 1;
		r_kid = l_kid + 1;

		if (arr[l_kid] > arr[par])
		{
			tmp = arr[par];
			arr[par] = arr[l_kid];
			arr[l_kid] = tmp;
			print_array(arr, total);
		}
		if (r_kid < size && arr[r_kid] > arr[par])
		{
			tmp = arr[par];
			arr[par] = arr[l_kid];
			arr[l_kid] = tmp;
			print_array(arr, total);
		}
		par--;
	}
}
