#include "sort.h"

/**
 * merge_subarray - Sorts subarray.
 * @subarray: subarray of an array of integers.
 * @temp: buffer to store sorted array.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarray(int *subarray, int *temp, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + front, mid - front);

	printf("[right]: ");
	print_array(subarray + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		temp[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < mid; i++)
		temp[k++] = subarray[i];
	for (; j < back; j++)
		temp[k++] = subarray[j];
	for (i = front, k = 0; i < back; i++)
		subarray[i] = temp[k++];

	printf("[Done] : ");
	print_array(subarray + front, back - front);

}
/**
 * merge_sort_recursive - Recursive function to apply merge sort.
 * @subarray: The array to be sorted.
 * @temp: The size of the array.
 * @left: The starting index of the subarray.
 * @right: The ending index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(subarray, temp, left, mid);
		merge_sort_recursive(subarray, temp, mid, right);
		merge_subarray(subarray, temp, left, mid, right);
	}
}
/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
