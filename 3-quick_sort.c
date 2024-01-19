#include "sort.h"
/**
 * swap - swap two int
 * @x: first int
 * @: second int
 * Return: nothing
*/
void swap(int *array, size_t size,int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array((const int *)array, size);
	}
}

/**
 * partitions - divide array
 * @array: array
 * @low: low 
 * @high: high
 * Return: integer
*/
size_t partitions(int *array, size_t size, ssize_t low, ssize_t high)
{
	int j , i;
	int pivot = array[high];

	for (i = j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, size, &array[j], &array[i++]);
		}
	}
	swap(array, size, &array[i], &array[high]);
	return (i);
}
/**
 * quick_sort_recur - recursive func to sort an array
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: array size
 * Return: nothing
*/
void quick_sort_recur(int *array, size_t size, ssize_t low, ssize_t high)
{
	size_t pivot;

	if (low < high)
	{
		pivot = partitions(array, size, low, high);
		quick_sort_recur(array, size, low, pivot - 1);
		quick_sort_recur(array, size, pivot + 1, high);
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
	quick_sort_recur(array, size, 0, size - 1);
}
