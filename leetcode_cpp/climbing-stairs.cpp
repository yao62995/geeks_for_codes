class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1 || n == 2) {
            return n;
        }
        int first = 2, second = 1;
        int i;
        int result ;
        for (i = 3; i <= n; i++) {
            result = first + second;
            second = first;
            first = result;
        }
        return result;
    }
};