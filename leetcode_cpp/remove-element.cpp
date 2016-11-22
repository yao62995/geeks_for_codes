class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 0) {
            return 0;
        }
        int i, begin, end;
        begin = 0;
        end = n - 1;
        while (A[begin] != elem && begin < n) {
            begin++;
        }
        while (A[end] == elem && end >= 0) {
            end--;
        }
        if (begin == n || begin > end) {
            return begin;
        }
        for (i = begin; i < end; i++) {
            if (A[i] == elem) {
                A[i] =  A[end];
                while (A[--end] == elem);
            }
        }
        return end + 1;
    }
};