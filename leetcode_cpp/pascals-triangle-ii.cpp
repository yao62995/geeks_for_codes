class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> data[2];
        data[0].push_back(1);
        data[1].push_back(1);
        vector<int>& pre = data[0];
        vector<int>& cur = data[1];
        int i, j;
        for (i = 1; i <= rowIndex; i++) {
            int pre_len = pre.size();
            cur.resize(pre_len + 1);
            for (j = 1; j < pre_len; j++) {
                cur[j] = pre[j - 1] + pre[j];
            }
            cur[pre_len] = 1;
            vector<int>& tmp = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};