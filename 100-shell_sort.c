#include "sort.h"

/**
 * shell_sort - Uses the Knuth sequence to sort an array in place
 * @array: Pointer to the first element in the array
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	int *gaps;
	unsigned int i;
	int j, k, temp, gap;

	if (!array || size < 2)
		return;

	gaps = gen_arr(size);

	for (i = 0; gaps[i] > 0; ++i)
	{
		gap = gaps[i];

		for (j = gap; j < size; j += 1)
		{
			temp = array[j];

			for (k = j; k >= gap && array[k - gap] > temp; k -= gap)
				array[k] = array[k - gap];

			array[k] = temp;
		}

	}

	free(gaps);
}

/**
 * my_pow - A function to get the result of an exponent
 * @b: The base
 * @x: The exponent
 *
 * Return: The result of b^x
 */
int my_pow(int b, unsigned int x)
{
	unsigned int i;
	int tot = 1;

	for (i = 0; i < x; ++i)
		tot *= b;

	return (tot);
}

/**
 * gen_arr - Generates an array of the Knuth sequence
 * @size: The size of the array to be sequenced
 *
 * Return: A malloc'd array of the intervals
 */
int *gen_arr(unsigned int size)
{
	int div_to;
	int *arr;
	unsigned int i, n_ele;

	div_to = (size / 3) * 2 + 1;
	div_to = div_to ? div_to : 1;

	for (n_ele = 0; div_to > 0; ++n_ele)
	{
		div_to += div_to % 3;
		div_to /= 3;
	}

	arr = malloc(sizeof(int) * n_ele + 1);

	for (i = 0; i < n_ele - 1; ++i)
		arr[i] = (my_pow(3, n_ele - i - 1) - 1) / 2;

	arr[i] = -1;

	return (arr);
}
