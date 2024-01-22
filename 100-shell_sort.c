#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t inteval, i, j;

	if (array == NULL || size < 2)
		return;

	for (inteval = 1; inteval < (size / 3);)
		inteval = inteval * 3 + 1;
	for (; inteval >= 1; inteval /= 3)
	{
		for (i = inteval; i < size; i++)
		{
			j = i;
			while (j >= inteval && array[j - inteval] > array[j])
			{
				swap(array + j, array + (j - inteval));
				j -= inteval;
			}
		}
		print_array(array, size);
	}
}
