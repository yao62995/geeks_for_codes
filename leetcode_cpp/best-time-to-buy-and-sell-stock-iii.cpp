class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int steps[2] = {0};  // store top two 
        int _low, _high;
        _low = _high = prices[0];
        int i;
        bool is_up = true;
        for (i = 1; i < prices.size(); i++) {
            int val = prices[i];
            if (is_up) {  // when up
                if (val >= _high) {
                    _high = val;
                } else {
                    is_up = false;
                    int _step = _high - _low;
                    if (_step > steps[0]) {
                        steps[1] = steps[0];
                        steps[0] = _step;
                    } else if (_step > steps[1]) {
                        steps[1] = _step;
                    }
                    _low = val;
                }
            } else {  // when down
                if (val <= _low) {
                    _low = val;
                } else {
                    is_up = true;
                    _high = val;
                }
            }
        }
        int result = steps[0];
        if (is_up) {
            int _step = _high - _low;
            if (_step > steps[1]) {
                result += _step;
            } else {
                result += steps[1];
            }
        } else {
            result += steps[1];
        }
        return result;
    }
};