#include "sort.h"

/**
 * swap- Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order.
 * @array: array
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t  i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}

	}
}
