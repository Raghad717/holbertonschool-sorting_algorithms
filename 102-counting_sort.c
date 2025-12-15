#include "sort.h"
#include <stdlib.h>

/**
* get_max - Finds the maximum value in an array
* @array: Array of integers
* @size: Size of the array
*
* Return: Maximum value
*/
int get_max(int *array, size_t size)
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

/**
* build_count_array - Builds and prints the counting array
* @array: Input array
* @size: Size of the array
* @max: Maximum value in array
*
* Return: Pointer to counting array
*/
int *build_count_array(int *array, size_t size, int max)
{
size_t i;
int *count = malloc(sizeof(int) * (max + 1));

if (!count)
return (NULL);

for (i = 0; i <= (size_t)max; i++)
count[i] = 0;

for (i = 0; i < size; i++)
count[array[i]]++;

for (i = 1; i <= (size_t)max; i++)
count[i] += count[i - 1];

print_array(count, max + 1);
return (count);
}

/**
* build_output_array - Builds the sorted array
* @array: Input array
* @output: Output array
* @count: Counting array
* @size: Size of the array
*/
void build_output_array(int *array, int *output, int *count, size_t size)
{
size_t i;

for (i = size; i > 0; i--)
{
output[count[array[i - 1]] - 1] = array[i - 1];
count[array[i - 1]]--;
}
}

/**
* counting_sort - Sorts an array of integers using Counting sort
* @array: Array to sort
* @size: Size of the array
*/
void counting_sort(int *array, size_t size)
{
int max, *count, *output;
size_t i;

if (!array || size < 2)
return;

max = get_max(array, size);

count = build_count_array(array, size, max);
if (!count)
return;

output = malloc(sizeof(int) * size);
if (!output)
{
free(count);
return;
}

build_output_array(array, output, count, size);

for (i = 0; i < size; i++)
array[i] = output[i];

free(count);
free(output);
}
