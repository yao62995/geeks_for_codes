class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        long long l_x = (long long)x;
        bool sign = true;
        if (l_x < 0) {
            sign = false;
            l_x = ~l_x + 1;
        }
        long long l_res = 0;
        while (l_x > 0) {
            int end = l_x % 10;
            l_x /= 10;
            l_res *= 10;
            l_res += end;
        }
        if (!sign) {
            l_res = ~l_res + 1;
        }
        return (int)l_res;
    }
};