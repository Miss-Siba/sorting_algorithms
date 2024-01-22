#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}
	return (maximum);
}

/**
 * counting_sort - sorts an array of integers using Counting sort.
 * @array: Array of integers
 * @size: Size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int *c, *sorted, maximum, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = get_max(array, size);

	c = malloc(sizeof(int) * (maximum + 1));

	if (c == NULL)
	{
		free(sorted);
		return;
	}
	for (i = 0; i < maximum; i++)
		c[i] = 0;
	for (i = 0; i < (int)size; i++)
		c[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		c[i] += c[i - 1];
	print_array(c, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[c[array[i]] - 1] = array[i];
		c[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(c);
}
