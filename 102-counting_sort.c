#include "sort.h"

/**
 * counting_sort - sorts an integer array using counting the sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * array is of size k + 1, where k is the largest number in the array
 */

void counting_sort(int *array, size_t size)
{
	size_t i, highest;
	int old, sum = 0;
	int *count, *new;

	if (array == NULL || size < 2)
		return;
	highest = find_highest(array, size);
	count = malloc(sizeof(int) * (highest + 1));
	if (count == NULL)
		return;
	for (i = 0; i < size; i++)
		++count[array[i]];
	for (i = 0; i <= highest; i++)
	{
		old = count[i];
		count[i] += sum;
		sum += old;
	}
	print_array(count, highest + 1);
	new = malloc(sizeof(int) * size);
	if (new == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		new[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = new[i];
	free(count);
	free(new);
}

/**
 * find_highest - finds the highest number in an array
 * @array: array
 * @size: size of the array
 * Return: highest number in the array
 */

int find_highest(int *array, size_t size)
{
	size_t i;
	int highest = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > highest)
			highest = array[i];
	}
	return (highest);
}
