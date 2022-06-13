#include "sort.h"
/**
 * quick_sort -
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	sort(array, start, end);
}

/**
 * sort - quick sort algorithm, recursively divides @array into 2 sides, sorted
 * w/ respect to eachother (no values in first side greater than right values)
 * @array: array to sort
 * @start: starting point of subarray
 * @end: endpoint of subarray
 */
void sort(int *array, size_t start, size_t end)
{
	size_t left, right;
	int pivot, aux;

	if (end - start < 2)
		return;
	pivot = array[start];
	left = start;
	right = end;
	while (1)
	{
		while (array[left] < pivot)
			left++;
		while (array[right] > pivot)
			right--;
		if (left >= right)
			break;
		aux = array[left];
		array[left] = array[right];
		array[right] = aux;
		print_array(array, 10);
	}
	sort(array, start, right + 1);
	sort(array, right + 1, end);
}
