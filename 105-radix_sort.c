#include "sort.h"

/**
 * radix_sort - Sorts using radix and the counting algorithms
 * @array: Pointer to the first element in the array
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i, width, w;
	int max;
	unsigned int count[10];
	int *output;

	if (!array || size < 2)
		return;

	for (max = array[0], i = 0; i < size; ++i)
		if (array[i] > max)
			max = array[i];

	for (width = 0; max; ++width)
		max /= 10;

	if (!width)
		return;

	output = malloc(sizeof(int) * size);

	for (w = 0; w < width; w++)
	{
		for (i = 0; i < 10; ++i)
			count[i] = 0;

		for (i = 0; i < size; ++i)
			count[key(array[i], w)]++;

		for (i = 1; i < 10; ++i)
			count[i] += count[i - 1];

		for (i = size - 1; i < size; --i)
			output[--count[key(array[i], w)]] = array[i];

		for (i = 0; i < size; ++i)
			array[i] = output[i];

		print_array(array, size);
	}
}

/**
 * key - Gets a key value given a number and a width
 * @val: The value to extract the key from
 * @width: The width to get the key from
 *
 * Return: The key to use
 */
unsigned int key(int val, int width)
{
	return ((val / my_pow(10, width)) % 10);
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
