#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, position;
	int minimum, change = 0;

	if (size < 2)
		return;

	/* loop through the array */
	for (; i < size; i++)
	{
	/* the smallest number is going to be in minimum */
		minimum = array[i];
		position = i;

	/* loop through next numbers */
		for (j = i + 1; j < size; j++)
		{
			/* if next is smallest than minimum, next is gonna be the new minimum */
			if (array[j] < minimum)
			{
				minimum = array[j];
				position = j;
				change = 1;
			}
		}
		/* switching positions and printing array */
		array[position] = array[i];
		array[i] = minimum;
		if (change == 1)
		{
			print_array(array, size);
			change = 0;
		}
	}
}
