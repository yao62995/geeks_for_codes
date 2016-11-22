class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return bi_search(A, 0, n - 1, target);
    }

    int bi_search(int A[], int begin, int end, int target) {
        if (begin > end) {
            return begin;
        }
        int middle = (begin + end) / 2;
        if (A[middle] == target) {
            return middle;
        } else if (A[middle] > target) {
            return bi_search(A, begin, middle - 1, target);
        } else {
            return bi_search(A, middle + 1, end, target);
        }
    }
};