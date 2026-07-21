#include <stdio.h>

/**
 * insertion_sort - sorts the nums array in-place.
 */
void insertion_sort(int nums[], int n)
{
	for (int i = 1; i < n; i++) {
		int key = nums[i];
		int j = i - 1;
		while (j >= 0 && key < nums[j]) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = key;
	}
}

void print_array(int nums[], int n)
{
	printf("[ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}
	printf("]\n");
}

int main()
{
	int nums[] = { 9, 4, 8, 5, 1, 7, 2 };
	int n = sizeof(nums) / sizeof(*nums);
	printf("before:\n");
	print_array(nums, n);

	printf("after:\n");
	insertion_sort(nums, n);
	print_array(nums, n);
	return 0;
}
