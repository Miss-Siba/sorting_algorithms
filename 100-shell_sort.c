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
 * shell_sort - Sorts an array of integers in ascending order using Shell sort.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;
	size_t temp;

	if (array == NULL || size < 2)
		return;

	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = i;

			for (j = i; j >= interval && array[j - interval] > array[temp];
				j -= interval)
			{
				swap(&array[j], &array[temp]);
				temp = j - interval;
			}
		}
		print_array(array, size);

		interval = (interval - 1) / 2;
	}
}
