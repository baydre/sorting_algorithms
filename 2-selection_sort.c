/*
 * sorting_algorithm, Task 2: function that sorts an
 * array of integers in ascending order using selection
 * sort algorithm.
 */
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using selection sort algorithm.
 * @array: array to be sorted.
 * @size: number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			int temp = array[i];

			array[i] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
