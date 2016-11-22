class Solution {
public:
    int min_index;
    int max_index;

    vector<int> searchRange(int A[], int n, int target) {
        max_index = -1;
        min_index = n;
        bi_search(A, 0, n - 1, target);
        if (min_index == n) { // not found
            min_index = -1;
        }
        vector<int> result;
        result.push_back(min_index);
        result.push_back(max_index);
        return result;
    }

    void bi_search(int A[], int begin, int end, int target) {
        if (begin > end) {
            return;
        }
        int middle = (begin + end) / 2;
        if (A[middle] == target) {
            if (middle > max_index) {
                max_index = middle;
            }
            if (middle < min_index) {
                min_index = middle;
            }
        }
        if (A[middle] <= target) {
            bi_search(A, middle + 1, end, target);
        } 
        if(A[middle] >= target) {
            bi_search(A, begin, middle - 1, target);
        }
    }
};