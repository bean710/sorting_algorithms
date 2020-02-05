#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - sorts an integer array in ascending order
 * @array: the array to be sorted.
 * @size: the size of the array
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

/**
 * split - recursively chops up the array, sendss it to be mmerged.
 * @buffer: a temp buffer to be used in merge
 * @array: the array to be sorted
 * @l: the leftest index
 * @r: the rightest index
 */
void split(int *buffer, int *array, int l, int r)
{
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		
		split(buffer, array, l, m - 1);
		split(buffer, array, m, r);

		merge(buffer, array, l, m, r);
	}
}

/**
 * merge - Puts a left and right array into sorted order.
 * @buffer: a temp buffer to be used in merge
 * @array: the array to be sorted
 * @l: the leftest index
 * @m: the middle index
 * @r: the rightest index
 */
void merge(int *buffer, int *array, int l, int m, int r)
{
	int i, j, k;

	for (i = l; i <= r; i++)
		buffer[i] = array[i];
	
	printf("Merging...\n");
	printf("[left]: ");
	print_array(buffer + l, m);
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
