#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define FUNC bubble_sort
#define NAME "Bubble Sort"
#define ITERATIONS 265413
#define ARRAY_SIZE 100

/**
 * TO COMPILE:
 * gcc -Wall -Wextra -Werror -pedantic 0-bubble_sort.c testing/timer.c print_array.c -o bubble
**/

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[ARRAY_SIZE];
    size_t n = sizeof(array) / sizeof(array[0]);
	clock_t t, p = clock();
	double time_taken;
	unsigned int i, j;

	srand(100);

	for (i = 0; i < ITERATIONS; ++i)
	{
		for (j = 0; j < ARRAY_SIZE; ++j)
			array[j] = rand() % (ARRAY_SIZE * 2);

		t = clock();
		FUNC(array, n);
		time_taken += difftime(clock(), t);
	}

    print_array(array, n);
    printf("\n");

	time_taken = time_taken / CLOCKS_PER_SEC;

    printf("Timing "NAME":\n");
	printf("%f total time (ms) for %d runs\n", time_taken * 1000, ITERATIONS);
	printf("%f average time (ms) taken per run\n", 
			time_taken / ITERATIONS * 1000);
	printf("%f estimated runs/sec (5%% error)\n", (1 / time_taken));
	printf("%f total program runtime (s)\n", 
			difftime(clock(), p)/CLOCKS_PER_SEC);

    return (0);
}
