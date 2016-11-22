class Solution {
public:
    int trap(int A[], int n) {
        int begin, end;
        for (begin = 0; begin < (n - 1); begin++) {
            if (A[begin + 1] < A[begin]) {
                break;
            }
        }
        for (end = n - 1; end > 0; end--) {
            if (A[end - 1] < A[end]) {
                break;
            }
        }
        int i, j, after_max;
        int container = 0;
        for (i = begin; i < end; ) {
            for (after_max = j = (i + 1); j <= end; j++) {
                if (A[after_max] < A[j]) {
                    after_max = j;
                }
                if (A[j] >= A[i]) {
                    break;
                }
            }
            if (j > end) {  // A[i] is to high
                j = after_max;
            }
            container += _trapContainer(A, i, j);
            for (; j < end; j++) {
                if (A[j + 1] < A[j]) {
                    break;
                }
            }
            i = j;
        }
        return container;
    }

    int _trapContainer(int A[], int a, int b) {
        int container = 0;
        int height;
        int begin, end;
        if (A[a] > A[b]) {
            height = A[b];
            begin = a + 1;
            end = b;
        } else {
            height = A[a];
            begin = a;
            end = b - 1;
        }
        int i;
        for (i = begin; i <= end; i++) {
            container += height - A[i];
        }
        return container;
    }
};