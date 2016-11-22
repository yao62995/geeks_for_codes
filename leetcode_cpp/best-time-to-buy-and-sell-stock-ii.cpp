class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int low, high;
        low = high = prices[0];
        int i;
        int result = 0;
        bool is_up = true;
        for (i = 1; i < prices.size(); i++) {
            int val = prices[i];
            if (is_up) {
                if (val > high) {
                    high = val;
                } else if (val < high){
                    is_up = false;
                    result += (high - low);
                    low = val;
                }
            } else {
                if (val > low) {
                    is_up = true;
                    high = val;
                } else {
                    low = val;
                }
            }
            
        }
        if (is_up) {
            result += (high - low);
        }
        return result;
    }
};