class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        int i, sum, max;
        max = sum = A[0];
        for (i = 1; i < n; i++) {
            if (sum > 0) {
                sum += A[i];
            } else {
                sum = A[i];
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};