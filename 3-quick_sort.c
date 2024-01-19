#include "sort.h"
/**
 * swap - swap two int
 * @x: first int
 * @: second int
 * Return: nothing
*/
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partitions - divide array
 * @array: array
 * @low: low 
 * @high: high
 * Return: integer
*/
int partitions(int *array, int low, int high, size_t size)
{
	int j , i = low - 1;
	int pivot = array[high];

	for (j = low; j < high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	if (array[high] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return i + 1;
}
/**
 * quick_sort_recur - recursive func to sort an array
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: array size
 * Return: nothing
*/
void quick_sort_recur(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partitions(array, low, high, size);
		quick_sort_recur(array, low, pivot - 1, size);
		quick_sort_recur(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recur(array, 0, size - 1, size);
}
