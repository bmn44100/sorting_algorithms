#include "sort.h"

/**
 * quick_sort_hoare - sorts an array using quicksort with hoare partition
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qsh(array, 0, size - 1, size);
}

/**
 * qsh - implements quicksort using the hoare method
 * @array: array to be sorted
 * @start: start index of array
 * @end: end index of array
 * @size: size of the array
 */

void qsh(int *array, ssize_t start, ssize_t end, size_t size)
{
	ssize_t p_i;

	if (start < end)
	{
		p_i = partition_h(array, start, end, size);
		qsh(array, start, p_i - 1, size);
		qsh(array, p_i, end, size);
	}
}

/**
 * partition_h - partitions an array into two subarrays using the hoare method
 * @array: array to be partitioned
 * @start: start index of array
 * @end: end index of array
 * @size: size of the array
 * Return: partition index of array
 */

ssize_t partition_h(int *array, ssize_t start, ssize_t end, size_t size)
{
	ssize_t left, right;
	int pivot;

	pivot = array[end];
	left = start - 1;
	right = end + 1;
	while (1)
	{
		do {
			left++;
		} while (array[left] < pivot);
		do {
			right--;
		} while (array[right] > pivot);
		if (left >= right)
			return (left);
		swap(&array[left], &array[right]);
		print_array(array, size);
	}
}

/**
 * swap - swaps integers
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
