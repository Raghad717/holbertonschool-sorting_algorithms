#include "sort.h"

/**
* swap_ints - Swaps two integers in an array
* @a: First integer
* @b: Second integer
*/
void swap_ints(int *a, int *b)
{
int tmp = *a;

*a = *b;
*b = tmp;
}

/**
* sift_down - Sifts down a node in a heap
* @array: Array representing the heap
* @size: Size of the array
* @start: Index to start sifting down
* @end: Last index of the heap
*/
void sift_down(int *array, size_t size, size_t start, size_t end)
{
size_t root = start, child, swap;

while ((child = root * 2 + 1) <= end)
{
swap = root;

if (array[swap] < array[child])
swap = child;

if (child + 1 <= end && array[swap] < array[child + 1])
swap = child + 1;

if (swap == root)
return;

swap_ints(&array[root], &array[swap]);
print_array(array, size);
root = swap;
}
}

/**
* heap_sort - Sorts an array using Heap sort
* @array: Array to sort
* @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
size_t start, end;

if (!array || size < 2)
return;

/* Build max heap */
for (start = (size - 2) / 2 + 1; start > 0; start--)
sift_down(array, size, start - 1, size - 1);

/* Extract elements from heap */
for (end = size - 1; end > 0; end--)
{
swap_ints(&array[0], &array[end]);
print_array(array, size);
sift_down(array, size, 0, end - 1);
}
}
