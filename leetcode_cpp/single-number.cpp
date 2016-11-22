class Solution {
public:
    int singleNumber(int A[], int n) {
        int i, num;
        for (i = 0; i < n; i++) {
            num ^= A[i];
        }
        return num;
    }
};