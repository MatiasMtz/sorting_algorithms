#include "sort.h"
/**
 * counting_sort - function that sorts an array of integers using the
 * Counting sort algorithm
 * @array: unsorted array
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	unsigned int count = 1, index = 0, max = array[0];
	int *buffer = NULL, *aux;

	if (array == NULL || size < 2)
		return;
	while (count < size)
	{
		if (max < (unsigned int)array[count])
			max = array[count];
		count++;
	}
	buffer = malloc(sizeof(int) * (++max));
	count = 0;
	while (count < max)
		buffer[count] = '\0', count++;
	count = 0;
	while (count < size)
		buffer[array[count]]++, count++;
	count = 1;
	while (count < max)
		buffer[count] = buffer[count] + buffer[count - 1], count++;
	print_array(buffer, max);
	count = 0;
	aux = malloc(sizeof(int) * size);
	while (count < size)
	{
		index = --buffer[array[count]];
		aux[index] = array[count];
		count++;
	}
	count = 0;
	while (count < size)
		array[count] = aux[count], count++;
	free(aux);
	free(buffer);
}
