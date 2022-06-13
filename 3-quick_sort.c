#include "sort.h"
/**
 * lomutoPartition - Positionate pivot and applies lomuto partition scheme
 * @array: unsorted integers array
 * @size: array size
 * @start: sub-array start bound
 * @end: sub-array end bound
 * Return: updated array index of pivot
 **/
int lomutoPartition(int *array, size_t size, int start, int end)
{
	int pivot, pivotIndex, aux, count;

	pivot = array[end];
	pivotIndex = start - 1;

	for (count = start; count < end; count++)
	{
		if (array[count] < pivot)
		{
			pivotIndex += 1;
			if (count != pivotIndex)
			{
				aux = array[count];
				array[count] = array[pivotIndex];
				array[pivotIndex] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[end] < array[pivotIndex + 1])
	{
		aux = array[pivotIndex + 1];
		array[pivotIndex + 1] = array[end];
		array[end] = aux;
		print_array(array, size);
	}
	return (pivotIndex + 1);
}

/**
 * quickSortRecursion - Sorts an array of integers using Quick sort algorithm
 * @array: array size
 * @size: array size
 * @start: sub-array start bound
 * @end: sub-array end bound
 **/
void quickSortRecursion(int *array, size_t size, int start, int end)
{
	int pivotIndex;

	if (start >= end)
		return;
	pivotIndex = lomutoPartition(array, size, start, end);
	quickSortRecursion(array, size, start, pivotIndex - 1);
	quickSortRecursion(array, size, pivotIndex + 1, end);
}

/**
 * quick_sort - wrapper function to call recursive quick sort func
 * @array: array size
 * @size: size of array
 **/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSortRecursion(array, size, 0, size - 1);
}
