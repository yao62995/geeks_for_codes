class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return 0;
        }
        long long result = 0;
        bool sign = true;
        long long l_dividend = (long long)dividend;
        long long l_divisor = (long long)divisor;
        if (l_dividend < 0) {
            l_dividend = ~l_dividend + 1;
            sign = !sign;
        }
        if (l_divisor < 0) {
            l_divisor = ~l_divisor + 1;
            sign = !sign;
        }
        long long _l_divisor;
        long long step;
        _l_divisor = l_divisor;
        step = 1;
        while (l_dividend >= _l_divisor) {
            result += step;
            l_dividend -= _l_divisor;
            step <<= 1;
            _l_divisor <<= 1;
        }
        while (_l_divisor >= l_divisor) {
            while (l_dividend >= _l_divisor) {
                result += step;
                l_dividend -= _l_divisor;
            }
            step >>= 1;
            _l_divisor >>= 1;
        }
        if (!sign && result > 0) {
            result = ~result + 1;
        }
        int _result = static_cast<int>(result);
        return _result;
    }
};