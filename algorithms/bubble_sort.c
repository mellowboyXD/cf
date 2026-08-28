#include <stdio.h>

void bubble_sort(int *nums, int n)
{
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                        if (nums[j] > nums[j + 1]) {
                                int temp = nums[j];
                                nums[j] = nums[j + 1];
                                nums[j + 1] = temp;
                        }
                }
        }
}

void print_array(int *nums, int n)
{
        for (int i = 0; i < n; i++) {
                printf("%d ", nums[i]);
        }
        printf("\n");
}
int main()
{
        int nums[] = {2, 4, 8, 1, 0};
        int n = sizeof(nums) / sizeof(*nums);

        printf("=== Before Bubble Sort ===\n");
        print_array(nums, n);

        bubble_sort(nums, n);

        printf("=== After Bubble Sort ===\n");
        print_array(nums, n);
}
