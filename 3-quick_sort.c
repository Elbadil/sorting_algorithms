#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array
 * @c: first element
 * @d: second element
*/

void swap_elements(int *c, int *d)
{
	int temp;

	temp = *c;
	*c = *d;
	*d = temp;
}


/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;

	quicksort_recurs(array, size, 0, size - 1);
}


/**
 * quicksort_recurs - performs quicksort on different parts on the array
 * @array: array of integers to be sorted
 * @size: size of the array
 * @first: lowest index in the array
 * @last: highest index in the array
*/

void quicksort_recurs(int *array, size_t size, int first, int last)
{
	int p_index;

	if (first < last)
	{
		p_index = array_partition(array, size, first, last);
		quicksort_recurs(array, size, first, p_index - 1);
		quicksort_recurs(array, size, p_index + 1, last);
	}
}


/**
 * array_partition - perform partition in an array of integers
 * @array: array of integers to be sorted
 * @size: size of the array
 * @first: lowest index in the array
 * @last: highest index in the array
 * Return: Pevot index
*/
int array_partition(int *array, size_t size, int first, int last)
{
	int pivot_v = array[last];
	int left = first;
	int right;

	for (right = first; right < last; right++)
	{
		if (array[right] <= pivot_v)
		{
			if (left < right)
			{
				swap_elements(&array[left], &array[right]);
				print_array(array, size);
			}
			left++;
		}
	}

	if (pivot_v != array[left])
	{
		swap_elements(&array[left], &array[last]);
		print_array(array, size);
	}

	return (left);
}
