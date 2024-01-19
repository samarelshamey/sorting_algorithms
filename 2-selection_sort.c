#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, min_pos;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_pos = i;
		for (j = 0; j < size; j++)
		{
			min_pos = j;
		}
	}
	if (min_pos != i)
	{
		temp = array[i];
		array[i] = array[min_pos];
		array[min_pos] = temp;
		print_array(array, size);
	}
}
