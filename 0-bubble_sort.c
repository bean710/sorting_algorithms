#include "sort.h"

/**
 * bubble_sort - sorts array of integers in ascending order with a bubble sort
 * @array: an array of integers
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	unsigned int i = 0, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		for (j = 0; j < size - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
