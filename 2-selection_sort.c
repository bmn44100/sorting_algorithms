#include "sort.h"

/**
 * selection_sort - the selection sort algo
 * @array: array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t shift, i, k;
	int tmp;

	if (array == NULL || size <= 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		shift = i;
		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[shift])
				shift = k;
		}
		if (shift != i)
		{
			tmp = array[i];
			array[i] = array[shift];
			array[shift] = tmp;
			print_array(array, size);
		}
	}
}
