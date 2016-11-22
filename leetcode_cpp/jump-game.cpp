class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        int i, j;
        int recent_valid = n - 1;
        for (i = n - 2; i >= 0; i--) {
            if ((i + A[i]) >= recent_valid) {
                recent_valid = i;
            }
        }
        if (recent_valid == 0) {
            return true;
        }
        return false;
    }
};