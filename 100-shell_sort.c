#include "sort.h"

/**
 * shell_sort - sorts an array of integers using the Shell sort algorithm
 * @array: unsorted array
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	unsigned int count, vl, gap;
	int aux;

	if (array == NULL || size < 2)
		return;
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (count = gap; count < size; count++)
		{
			aux = array[count];
			for (vl = count; vl >= gap && array[vl - gap] > aux; vl -= gap)
				array[vl] = array[vl - gap];
			array[vl] = aux;
		}
		print_array(array, size);
	}
}
