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
 * sift_down - Perform sift-down operation in a heap.
 * @array: The array to be sifted.
 * @size: The size of the array.
 * @root: The root index of the heap.
 * @end: The last index of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t max_child, swap, left_child, right_child;

    while ((left_child = (2 * root) + 1) <= end)
    {
        max_child = left_child;
        right_child = left_child + 1;

        if (right_child <= end && array[right_child] > array[left_child])
            max_child = right_child;

        if (array[root] < array[max_child])
        {
            swap = array[root];
            array[root] = array[max_child];
            array[max_child] = swap;
            print_array(array, size);
            root = max_child;
        }
        else
        {
            break;
        }
    }
}

/**
 * heapify - Build a max heap from the array.
 * @array: The array to be transformed into a heap.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
    size_t start;

    for (start = (size - 2) / 2; (int)start >= 0; start--)
        sift_down(array, size, start, size - 1);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    size_t end;

    if (array == NULL || size < 2)
        return;

    heapify(array, size);

    for (end = size - 1; end > 0; end--)
    {
        int swap = array[0];
        array[0] = array[end];
        array[end] = swap;
        print_array(array, size);

        sift_down(array, size, 0, end - 1);
    }
}
