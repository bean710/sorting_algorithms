#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * quick_sort - sorts an array of integers in ascending order.
 * @array: the array to be sorted.
 * @size: the size of the array.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_extra(array, 0, (int)size - 1, size);
}

/**
 * quick_sort_extra - sorts an array of integers in asceding order.
 * @array: the array to be sorted.
 * @lo: the beginning of the array
 * @hi: the end of the array
 * @size: the size of the original array
 */
void quick_sort_extra(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_sort_extra(array, lo, pivot - 1, size);
		quick_sort_extra(array, pivot + 1, hi, size);
	}
}

/**
 * partition - partitions an array of integers in asceding order.
 * @array: the array to be sorted.
 * @lo: the beginning of the array
 * @hi: the end of the array
 * @size: the size of the original array
 * Return: the index of the last swap
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int temp;
	int i = lo;
	int j = lo;

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			if (array[i] != array[j])
			{
				print_array(array, size);
			}
			i++;
		}
	}
	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;
	if (array[i] != array[hi])
	{
		print_array(array, size);
	}

	return (i);
}
