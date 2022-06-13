#include "sort.h"

size_t mysize;

/**
 * quick_sort -
 *
 * @array: array to sort
 *
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int start, end;

	start = 0;
	mysize = size;
	end = size - 1;
	sort(array, start, end);
}

/**
 * sort - quick sort algorithm, recursively divides @array into 2 sides, sorted
 * w/ respect to eachother (no values in first side greater than right values)
 *
 * @array: array to sort
 *
 * @start: starting point of subarray
 *
 * @end: endpoint of subarray
 */
void sort(int *array, size_t start, size_t end)
{
	size_t left, right;
	int pivot;

	if (end - start < 2)
		return;
	pivot = array[start];
	left = start - 1;
	right = end + 1;
	while (1)
	{
		do
			left++;
		while (array[left] < pivot);
		do
			right--;
		while (array[right] > pivot);
		if (left >= right)
			break;
		swap(array, left, right);
		print_array(array, 10);
	}
	sort(array, start, right + 1);
	sort(array, right + 1, end);
}

/**
 * swap - swap two array element values
 *
 * @array: array
 * @a: index of first value to swap
 * @b: index of second value to swap
 */
void swap(int *array, size_t a, size_t b)
{
	int swap_in;

	swap_in = array[a];
	array[a] = array[b];
	array[b] = swap_in;
}
