#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* merge_print - Prints merging process
* @array: Array being merged
* @left: Left index
* @mid: Middle index
* @right: Right index
*/
void merge_print(int *array, size_t left, size_t mid, size_t right)
{
size_t i;

printf("Merging...\n");
printf("[left]: ");
for (i = left; i < mid; i++)
{
printf("%d", array[i]);
if (i + 1 < mid)
printf(", ");
}
printf("\n[right]: ");
for (i = mid; i < right; i++)
{
printf("%d", array[i]);
if (i + 1 < right)
printf(", ");
}
printf("\n");
}

/**
* merge - Merges two sorted subarrays
* @array: Main array
* @buffer: Temporary buffer
* @left: Left index
* @mid: Middle index
* @right: Right index
*/
void merge(int *array, int *buffer,
size_t left, size_t mid, size_t right)
{
size_t i = left, j = mid, k = left;

merge_print(array, left, mid, right);

while (i < mid && j < right)
buffer[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];

while (i < mid)
buffer[k++] = array[i++];

while (j < right)
buffer[k++] = array[j++];

for (i = left; i < right; i++)
array[i] = buffer[i];

printf("[Done]: ");
for (i = left; i < right; i++)
{
printf("%d", array[i]);
if (i + 1 < right)
printf(", ");
}
printf("\n");
}

/**
* merge_sort_recursive - Recursive merge sort
* @array: Array to sort
* @buffer: Temporary buffer
* @left: Left index
* @right: Right index
*/
void merge_sort_recursive(int *array, int *buffer,
size_t left, size_t right)
{
size_t mid;

if (right - left < 2)
return;

mid = left + (right - left) / 2;

merge_sort_recursive(array, buffer, left, mid);
merge_sort_recursive(array, buffer, mid, right);
merge(array, buffer, left, mid, right);
}

/**
* merge_sort - Sorts an array using merge sort
* @array: Array to sort
* @size: Size of the array
*/
void merge_sort(int *array, size_t size)
{
int *buffer;

if (!array || size < 2)
return;

buffer = malloc(sizeof(int) * size);
if (!buffer)
return;

merge_sort_recursive(array, buffer, 0, size);
free(buffer);
}
