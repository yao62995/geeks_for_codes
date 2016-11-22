class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) {
            return n;
        }
        int pi, pj;
        for (pi = 0, pj = 1; pj < n; pj++) {
            if (A[pj] == A[pj - 1]) {
                continue;
            }
            pi++;
            if (pj > pi) {
                A[pi] = A[pj];
            }
        }
        return (pi + 1);
    }
};