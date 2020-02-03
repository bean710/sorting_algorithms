#include "sort.h"

/**
 * selection_sort - Sorts an array in place using selection sort
 * @array: Pointer to the array
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, s;
	int tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; ++i)
	{
		s = i;
		for (j = i; j < size; ++j)
		{
			if (array[j] < array[s])
				s = j;
		}
		tmp = array[i];
		array[i] = array[s];
		array[s] = tmp;
		print_array(array, size);
	}
}
