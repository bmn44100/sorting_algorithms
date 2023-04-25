#include "sort.h"

/**
 * shell_sort - sorts an integer array using shell the sort algorithm
 * @array: array to be  sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, k, space = 1;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (space < size)
		space = (space - 1) / 3;
	while (space > 0)
	{
		for (i = space; i < size; i++)
		{
			tmp = array[i];
			for (k = i; k >= space && array[k - space] > tmp; k -= space)
			{
				array[k] = array[k - space];
			}
			array[k] = tmp;
		}
		space = (space - 1) / 3;
		print_array(array, size);
	}
}
