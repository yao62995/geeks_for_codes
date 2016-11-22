class Solution {
public:
    bool result;

    bool search(int A[], int n, int target) {
        if (n == 0) {
            return false;
        }
        int end = n - 1;
        while (A[end] == A[0] && end > 0) {
            end--;
        }
        if (end == 0) {  // all equal
            return (A[0] == target);
        }
        if (target < A[0] && target > A[end]) {
            return false;
        }
        bi_search(A, 0, end, target);
        return result;
    }

    void bi_search(int A[], int begin, int end, int target) {
        if (begin > end) { // not found
            result = false;
            return;
        }
        int middle = (begin + end) / 2;
        if (A[middle] == target) {
            result = true;
            return;
        }
        bool use_which;  // true -> left,  false -> right
        if (middle == begin) {
            use_which = false;
        } else if (A[middle] > A[begin]) {
            if (target < A[middle] && target >= A[begin]) {
                use_which = true;
            } else {
                use_which = false;
            }
        } else if (A[middle] < A[begin]) {
            if (target > A[middle] && target <= A[end]) {
                use_which = false;
            } else {
                use_which = true;
            }
        } else {
            use_which = false;
        }
        int new_begin, new_end;
        if (use_which) {
            new_begin = begin;
            new_end = middle - 1;
        } else {
            new_begin = middle + 1;
            new_end = end;
        }
        resize(A, new_begin, new_end);
        bi_search(A, new_begin, new_end, target);
    }

    void resize(int A[], int &begin, int &end) {
        if (begin >= end) {
            return;
        }
        if (A[begin] == A[end]) {
            begin = end;
        } else {
            int middle = (begin + end) / 2;
            if (A[begin] == A[middle]) {
                begin = middle;
            } else if (A[end] == A[middle]) {
                end = middle;
            }
        }
    }
};