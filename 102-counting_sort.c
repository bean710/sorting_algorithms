#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array with no comparisons
 * @array: Pointer to the array of integers
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	unsigned int *count;
	size_t i, c_size;
	int max, *output;

	for (i = 0, max = array[0]; i < size; ++i)
		if (array[i] > max)
			max = array[i];

	c_size = max + 1;
	count = malloc(sizeof(unsigned int) * c_size);
	output = malloc(sizeof(int) * size);

	for (i = 0; i < c_size; ++i)
		count[i] = 0;

	for (i = 0; i < size; ++i)
		++count[array[i]];

	for (i = 1; i < c_size; ++i)
		count[i] += count[i - 1];

	for (i = 0; i < c_size; ++i)
		printf("%u%s", count[i], i != c_size - 1 ? ", " : "\n");

	for (i = 0; i < size; ++i)
	{
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}

	for (i = 0; i < size; ++i)
		array[i] = output[i];

	free(output);
	free(count);
}
