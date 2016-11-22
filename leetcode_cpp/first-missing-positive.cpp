class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i;
        int result = 0;
        for (i =0; i < n; i++) {
            if (A[i] == (i + 1)) {  // in right position
                continue;
            } else if (A[i] > n || A[i] < 0) { // when A[i] larger than n, set 0
                A[i] = 0;
            } if (A[i] > 0) {
                int cur = A[i] - 1;
                A[i] = 0;
                int next = A[cur] - 1;
                A[cur] = cur + 1;
                while (next >= 0) {
                    if (A[next] > n || A[next] <= 0) {
                        A[next] = next + 1;
                        break;
                    } else if (A[next] == (next + 1)) {
                        break;
                    }
                    cur = next;
                    next = A[cur] - 1;
                    A[cur] = cur + 1;
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (A[i] == 0) {
                result = i + 1;
                break;
            }
        }
        if (result == 0) {
            result = n + 1;
        }
        return result;
    }
};