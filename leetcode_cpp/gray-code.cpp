class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if (n == 0) {
            return result;
        }
        result.push_back(1);
        if (n == 1) {
            return result;
        }
        int i, j;
        for (i = 1; i < n; i++) {
            int cur = 1 << i;
            int size = result.size();
            for (j = (size - 1); j >= 0; j--) {
                result.push_back(cur | result[j]);
            }
        }
        return result;
    }
};