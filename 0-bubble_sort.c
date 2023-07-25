#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Print the array after every swap */
				for (k = 0; k < size; k++)
				{
					if (k != size - 1)
					{
						printf("%d, ", array[k]);
					}
					else
						printf("%d", array[k]);
				}
				printf("\n");
			}
		}
	}
}
