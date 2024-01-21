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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int right, int left)
{
	int *pivot, high, low;

	pivot = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}
	if (array[high] > *pivot)
	{
		swap(array + high, pivot);
		print_array(array, size);
	}
	return (high);
}

/**
 * quick_lomuto_sort - recursively sorts an array.
 * @array: array
 * @size: size of the array.
 * @high: highest index
 * @low: lowest index
 */
void quick_lomuto_sort(int *array, size_t size, int left, int right)
{
	int section;

	if (right > left)
	{
		section = lomuto_partition(array, size, right, left);
		quick_lomuto_sort(array, left, section - 1, size);
		quick_lomuto_sort(array, right, section + 1, size);
	}
}

/**
 * quick_sort- sorts an array of integers in ascending order using quick sort.
 * @array: array size
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_lomuto_sort(array, 0, size, size - 1);
}
