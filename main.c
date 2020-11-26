#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void display(const int *nums, const int len) {
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maximumGap(int* nums, int numsSize){
    if (nums == NULL || numsSize < 2) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int maxGap = 0;
    for (int i = 1; i < numsSize; i++)
    {
        int gap = nums[i] - nums[i - 1];
        maxGap = maxGap > gap ? maxGap : gap;
    }
    return maxGap;
}

int main(int argc, char const *argv[])
{
    int nums[] = {3,6,9,1};
    if (maximumGap(&nums, 4) == 3) {
        return 1;
    }
    return 0;
}
