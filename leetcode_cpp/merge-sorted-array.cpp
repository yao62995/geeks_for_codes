class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n <= 0) {
            return;
        }
        int pa, pb, pc;
        pa = m - 1;
        pb = n - 1;
        pc = m + n - 1;
        while (pa >= 0 && pb >= 0) {
            if (A[pa] > B[pb]) {
                A[pc--] = A[pa--];
            } else {
                A[pc--] = B[pb--];
            }
        }
        if (pa < 0) {
            while (pb >= 0) {
                A[pc--] = B[pb--];
            }
        }
    }
};