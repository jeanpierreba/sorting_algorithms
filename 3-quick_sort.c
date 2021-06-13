#include "sort.h"

/**
 * swap_a - A utility function to swap two elements
 * @array: array containing the positions to swap
 * @low: index of the lower element to swap
 * @high: index of the high element to swap
 * @size: size of the array
 */

void swap_a(int *array, int low, int high, size_t size)
{
	int tmp;

	if (array[low] != array[high])
	{
		tmp = array[low];
		array[low] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
}

/**
 * quick_sort2 - sorts an array in ascending order
 * Takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot
 * @array: array to sort
 * @low: index of the lower element
 * @high: index of the high element
 * @size: size of the array
 */

void quick_sort2(int *array, int low, int high, size_t size)
{
	int pi, pivot = array[high], i = low, j;

	if (low < high)
	{
		for (j = low; j <= high; j++)
		{
			if (array[j] < pivot)
			{
				swap_a(array, i, j, size);
				i++;
			}
		}
		swap_a(array, i, high, size);

		pi = i;
		quick_sort2(array, low, pi - 1, size);
		quick_sort2(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - send the correct input for recursive quick_sort2
 * @array: array to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (!array || !array[0] || size < 2)
		return;

	quick_sort2(array, low, high, size);
}
