#include "sort.h"

/**
* sort_needed - check if the array is not sorted
* @array: array to be checked
* @size: size of the array to be checked
* Return: 1 if the list require to be sorted
*/
int sort_needed(int *array, size_t size)
{
	unsigned int i;

	for (i = 0; i < size - 1;  i++)
	{
		if (array[i] > array[i + 1])
			return (1);
	}
	return (0);
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	unsigned int i;

	if (size < 2)
		return;

	while (sort_needed(array, size))
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{ /* swap */
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
