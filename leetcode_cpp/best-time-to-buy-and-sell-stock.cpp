class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int min, max, _min, _max;
        min = max = _min = _max = prices[0];
        int i; 
        for (i = 1; i < prices.size(); i++) {
            int val = prices[i];
            if (val > _max) {
                _max = val;
            } else if(val < _min) {
                if ((_max - _min) > (max - min)) {
                    min = _min;
                    max = _max;
                }
                _min = _max = val;
            }
        }
        int result = max - min;
        if (result < (_max - _min)) {
            result = _max - _min;
        }
        return result;
    }
};