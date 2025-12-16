#include "sort.h"

/**
* swap - Swaps two integers
* @a: First integer
* @b: Second integer
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* hoare_partition - Partitions array using Hoare scheme
* @array: The array to partition
* @low: Starting index
* @high: Ending index
* @size: Size of array (for printing)
* Return: The partition index
*/
int hoare_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j = high + 1;

while (1)
{
/* Find element from left that is >= pivot */
do {
i++;
} while (array[i] < pivot);

/* Find element from right that is <= pivot */
do {
j--;
} while (array[j] > pivot);

/* If pointers have met or crossed */
if (i >= j)
return (j);

/* Swap elements */
swap(&array[i], &array[j]);
print_array(array, size);
}
}

/**
* quick_sort_recursive - Recursively sorts array using quick sort
* @array: The array to sort
* @low: Starting index
* @high: Ending index
* @size: Size of array (for printing)
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
int pi;

if (low < high)
{
pi = hoare_partition(array, low, high, size);
quick_sort_recursive(array, low, pi, size);
quick_sort_recursive(array, pi + 1, high, size);
}
}

/**
* quick_sort_hoare - Sorts an array of integers in ascending order
* using the Quick sort algorithm with Hoare partition scheme
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
