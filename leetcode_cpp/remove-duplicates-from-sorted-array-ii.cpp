class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) {
            return n;
        }
        int pos_i, pos_j;
        for (pos_i = 0; (pos_i + 2) < n; pos_i++) {
            if (A[pos_i] == A[pos_i + 2]) {
                break;
            }
        }
        for (pos_j = pos_i; (pos_j + 2) < n; ) {
            int val = A[pos_j];
            if (A[pos_j + 2] == val) {
                int k;
                for (k = 3; (pos_j + k) < n; k++) {
                    if (val != A[pos_j + k]) {
                        break;
                    }
                }
                A[pos_i] = val;
                A[pos_i + 1] = val;
                pos_i += 2;
                pos_j = pos_j + k;
            } else {
                A[pos_i++] = A[pos_j++];
            }
        }
        while (pos_j < n) {
            A[pos_i++] = A[pos_j++];
        }
        return pos_i;
    }
};