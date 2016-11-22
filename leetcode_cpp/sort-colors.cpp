class Solution {
public:
    void sortColors(int A[], int n) {
        if (n <= 1) {
            return;
        }
        int begin, middle, end;
        begin = 0;
        end = n - 1;
        while (begin < end) {
            if (A[end] == 2) {
                while (end >= 0 && A[end] == 2) {
                    end--;
                }
                continue;
            }
            if (A[begin] == 0) {
                while (begin < n && A[begin] == 0) {
                    begin++;
                }
                continue;
            }
            if (A[begin] == 2) {
                swap(A, begin, end);
            } else {   // A[begin] == 1
                if (A[end] == 0) {  // A[begin] == 1 && A[end] == 0
                    swap(A, begin, end);
                } else {  // A[begin] == 1 && A[end] == 1
                    int middle = begin + 1;
                    while (middle < end && A[middle] != 2) {
                        middle++;
                    }
                    if (A[middle] != 2) {  // no number 2 exsit in [begin, end]
                        _sortTwoColor(A, begin, end);
                        return;
                    } else {
                        swap(A, begin, middle);
                    }
                } // end else
            }  // end else
        }  // end while
    }

    // do when only number 0/1 in range[begin, end]
    void _sortTwoColor(int A[], int begin, int end) {
        int left_i, right_i;
        left_i = begin;
        right_i = end;
        while (left_i < right_i) {
            while (left_i < right_i && A[left_i] == 0) {
                left_i++;
            }
            while (right_i > left_i && A[right_i] == 1) {
                right_i--;
            }
            if (left_i < right_i) {
                swap(A, left_i, right_i);
            }
        }
    }

    void swap(int A[], int i, int j) {
        if (i != j) {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
};