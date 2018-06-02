#include "sort.h"
/**
 *print_merge - prints the merging syntax
 *@array: the array to sort
 *@left: the leftmost index of the subarray
 *@right: the right index of the subarray
 *
 *Return: void
 */
void print_merge(int *array, int left, int right)
{
	int i = left;

	while (i <= right)
	{
		printf("%d", array[i]);
		if (i != right)
			printf(", ");
		else
			printf("\n");
		i++;
	}
}

/**
 *merge - merges subarrays back in order
 *@dup: the duplicate array
 *@array: the array to be sorted
 *@left: the left index
 *@middle: the middle index (ie boundary)
 *@right: the right index
 *
 */
void merge(int *dup, int *array, int left, int middle, int right)
{
	int i = left, j = middle + 1, k = left;

	while (k <= right)
	{
		if (i <= middle && (j > right || array[i] < array[j]))
		{
			dup[k] = array[i];
			i++;
		}

		else
		{
			dup[k] = array[j];
			j++;
		}
		k++;
	}

}

/**
 *merge_break - merge sort with indices
 *@array: the array to sort
 *@left: the left index of the subarray
 *@right: the right index of the subarray
 *@dup: duplicate array
 *
 *Return: void
 */
void merge_break(int *array, int left, int right, int *dup)
{
	int middle;

	if (left >= right)
		return;

	if ((right - left) % 2 == 0)
		middle = ((right - left) / 2) + left - 1;
	else
		middle = ((right - left) / 2) + left;

	merge_break(dup, left, middle, array);
	merge_break(dup, middle + 1, right, array);

	printf("Merging...\n");
	printf("[left]: ");
	print_merge(dup, left, middle);

	printf("[right]: ");
	print_merge(dup, middle + 1, right);

	merge(array, dup, left, middle, right);

	printf("[Done]: ");
	print_merge(array, left, right);
}

/**
 *merge_sort - sorts an array of integers in ascending order via merge sort
 *@array: the array of integers to sort
 *@size: the size of the array
 *
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *duplicate;

	duplicate = malloc(sizeof(int) * size);
	if (duplicate == NULL)
		return;

	while (i < size)
	{
		duplicate[i] = array[i];
		i++;
	}

	merge_break(array, 0, size - 1, duplicate);

	free(duplicate);
}
