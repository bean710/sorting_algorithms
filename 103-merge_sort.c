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
	split(buffer, array, 0, size - 1);
	free(buffer);
}

void split(int *buffer, int *array, int l, int r)
{
	int m, diff;

	if (l < r)
	{
		diff = r - l;
		diff += diff % 2;
		m = l + diff / 2;
		
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
	
	printf("Merging...\n");
	printf("[left]: ");
	print_array(buffer + l, m - l);
	printf("[right]: ");
	print_array(buffer + m, r - m + 1);
	
	i = l;
	j = m;
	k = l;
	
	while (k <= r)
	{
		if (i < m && j <= r)
		{
			if (buffer[i] > buffer[j])
				array[k++] = buffer[j++];
			else
				array[k++] = buffer[i++];
		}
		else if (i < m)
			array[k++] = buffer[i++];
		else
			array[k++] = buffer[j++];
	}
	
	printf("[Done]: ");
	print_array(array + l, r - l + 1);
}
