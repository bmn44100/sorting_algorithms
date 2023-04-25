#include "sort.h"

/**
 * counting_sort - sorts an integer array using counting the sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * array is of size k + 1, where k is the largest number in the array
 */

void counting_sort(int *array, size_t size)
{
	size_t i, max;
	int old, total = 0;
	int *count, *new;

	if (array == NULL || size < 2)
		return;
	max = find_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (i = 0; i < size; i++)
		++count[array[i]];
	for (i = 0; i <= max; i++)
	{
		old = count[i];
		count[i] += total;
		total += old;
	}
	print_array(count, max + 1);
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
 * find_max - finds the highest number in an array
 * @array: array
 * @size: size of the array
 * Return: highest number in the array
 */

int find_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
