#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order
* using the Shell sort algorithm with Knuth sequence
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j;
int temp;

if (array == NULL || size < 2)
return;

/* Calculate initial gap using Knuth sequence: n+1 = n * 3 + 1 */
while (gap < size / 3)
gap = gap * 3 + 1;

/* Start with the largest gap and work down to 1 */
while (gap > 0)
{
/* Do a gapped insertion sort for this gap size */
for (i = gap; i < size; i++)
{
/* Store current element */
temp = array[i];
/*
* Shift earlier gap-sorted elements up until the correct location
*for array[i] is found
*/
j = i;
while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}

/* Put temp (the original array[i]) in its correct location */
array[j] = temp;
}

/* Print the array after decreasing the interval */
print_array(array, size);

/* Calculate next gap using Knuth sequence: gap = (gap - 1) / 3 */
gap = (gap - 1) / 3;
}
}
