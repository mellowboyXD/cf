#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buffer[102] = { 0 };
    int nums[51] = {0};
    int count = 0;

	char *str = fgets(buffer, sizeof(buffer), stdin);
	assert(str && "could not read input");

    int n = strlen(str);

    // populate nums array
    for (int i = 0; i < n; i++) {
        if (!isdigit(str[i]))
            continue;
        nums[count++] = str[i] - '0';
    }

    // bubble sort
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    // output in required format
    for (int i = 0; i < count; i++) {
        printf("%d", nums[i]);
        if (i != count - 1)
            printf("+");
    }
    printf("\n");

	return 0;
}
