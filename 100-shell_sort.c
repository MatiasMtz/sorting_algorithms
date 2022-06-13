#include "sort.h"
/**
 * shell_sort - sorts an array of integers using the Knuth sequence
 * @array: unsorted array
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, count = 0, value = 0;
	int aux = 0;

	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		value = gap;
		while (value < size)
		{
			aux = array[value];
			count = value;
			while (count > gap - 1 && array[count - gap] >= aux)
			{
				array[count] = array[count - gap];
				count -= gap;
			}
			array[count] = aux;
			value++;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
