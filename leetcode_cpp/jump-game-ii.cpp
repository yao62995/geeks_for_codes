class Solution {
public:
    int jump(int A[], int n) {
        if (n == 1) {
            return 0;
        }
        int* steps = (int *)malloc(sizeof(int) * n);
        int* least_mins = (int *)malloc(sizeof(int) * n);
        memset(steps, 0, sizeof(int) * n);
        memset(least_mins, 0, sizeof(int) * n);
        int i;
        int min_valid_pos;
        for (i = n - 2; i >= 0; i--) {
            if (A[i] == 0) {
                steps[i] = 0x7FFFFFFF;
                continue;
            }
            if (i + A[i] >= (n - 1)) {
                steps[i] = 1;
            } else {
                
            }
        }
        int result = steps[0];
        free(least_mins);
        free(steps);
        return result;
    }
};