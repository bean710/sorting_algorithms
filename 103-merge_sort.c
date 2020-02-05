#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		exit(EXIT_FAILURE);
	splitter(buffer, array, 0, size - 1);
	free(buffer);
}

void split(int *buffer, int *array, int l, int r)
{
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2
		
		split(buffer, array, l, m - 1);
		split(buffer, array, m, r);

		merge(buffer, array, l, m, r);
	}
}

/**
 *
 */
void merge(int *buffer, int *array, int l, int m, int r)
{
	int i, j, k;

	for (i = l; i <= r; i++)
		buffer[i] = array[i];
}
