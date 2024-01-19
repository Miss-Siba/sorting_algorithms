#include "sort.h"
#include <stdbool.h>
/**
 * bubble_sort - sorts array using Bubble sort algorithm.
 * @array: array to be sorted.
 * @size: size of array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;

			}
		}
		if (swapped)
		{
			print_array(array, size);
		}
	}
}
