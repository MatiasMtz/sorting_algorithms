#include "sort.h"
/**
 * selection_sort - sorts an array following the selection sort algorithm
 * @array: array to sort
 * @size: size of the array;
 */
void selection_sort(int *array, size_t size)
{
	unsigned int count = 0, value = 0, countAux = 0;
	int aux = 0;

	if (array == NULL || size < 2)
		return;

	for (count = 0; count < size; count++)
	{
		countAux = count;
		for (value = count + 1; value < size; value++)
		{
			if (array[value] < array[countAux])
				countAux = value;
		}
		aux = array[count];
		array[count] = array[countAux];
		array[countAux] = aux;
		if (count != countAux)
			print_array(array, size);
	}
}
