#include "sort.h"

/**
 * selection_sort - Sorts an array using Selection sort algorithm
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		/* Find the minimum element in unsorted part */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		/* Swap if minimum element is not at current position */
		if (min_idx != i)
		{
			/* Swap elements */
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			/* Print array after swap */
			print_array(array, size);
		}
	}
}
