class Solution {
public:
    int sqrt(int x) {
        double y = (double)x;
        while (abs(y * y - x) > 0.1) {
            y = (y + x / y) / 2.0;
        }
        int result = (int)y;
        return result;
    }
};