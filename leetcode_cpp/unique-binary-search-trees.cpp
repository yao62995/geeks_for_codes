class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) {
            return n;
        }
        int* nums = (int *)malloc(sizeof(int) * (n + 1));
        memset(nums, 0, sizeof(int) * (n + 1));
        nums[0] = nums[1] = 1;
        int i, j;
        for (i = 2; i <= n; i++) {
            for (j = 0; j < i; j++) {
                nums[i] += nums[j] * nums[i - 1 - j];
            }
        }
        int result = nums[n];
        free(nums);
        return result;
    }
};