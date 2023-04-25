#include "sort.h"

/**
 * quick_sort - quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - recursively implements the quicksore algorithm
 * @array: array to be sorted
 * @start: start index of array
 * @end: end index of array
 * @size: size of the array
 */

void quicksort(int *array, ssize_t start, ssize_t end, size_t size)
{
	ssize_t index_i;

	if (start < end)
	{
		index_i = partition(array, start, end, size);
		quicksort(array, start, index_i - 1, size);
		quicksort(array, index_i + 1, end, size);
	}
}

/**
 * partition - partitions an array into two subarrays
 * @array: array to be partitioned
 * @start: start index of array
 * @end: end index of array
 * @size: size of the array
 * Return: partition index
 */

ssize_t partition(int *array, ssize_t start, ssize_t end, size_t size)
{
	ssize_t index_i, k;
	int shift;

	index_i = start - 1;
	shift = array[end];
	for (k = start; k <= end - 1; k++)
	{
		if (array[k] <= shift)
		{
			index_i++;
			if (index_i != k)
			{
				swap(&array[index_i], &array[k]);
				print_array(array, size);
			}
		}
	}
	if (array[end] < array[index_i + 1])
	{
		swap(&array[end], &array[index_i + 1]);
		print_array(array, size);
	}
	return (index_i + 1);
}

/**
 * swap - swaps integers a and b
 * @a: first integer to be swapped
 * @b: second integer to be swapped
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
