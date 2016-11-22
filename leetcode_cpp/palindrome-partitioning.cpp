class Solution {
public:
    vector<vector<string> > result;

    vector<vector<string> > partition(string s) {
        int i, j, m;
        int len = s.length();
        bool* dp = (bool*)malloc(sizeof(bool) * len * len);
        for (i = 0; i < len; i++) {
            for (j = 0; j < len; j++) {
                if (i >= j) {
                    dp[i * len + j] = true;
                } else {
                    dp[i * len + j] = false;
                }
            }
        }
        // find multi elements
        for (m = 1; m < len; m++) {
            for (i = 0; (i + m) < len; i++) {
                j = i + m;
                if (s[i] != s[j]) {
                    dp[i * len + j] = false;
                } else {
                    dp[i * len + j] = dp[(i + 1) * len + (j - 1)];
                }
            }
        }
        // 
        vector<string> path;
        GetPalindrome(dp, 0, len, path, s);
        return result;
    }

    void GetPalindrome(bool* dp, int pos, int len, vector<string> &path, string& s) {
        if (pos >= len) {
            result.push_back(path);
            return;
        }
        int j;
        for (j = pos; j < len; j++) {
            if (dp[pos * len + j]) {
                path.push_back(s.substr(pos, j - pos + 1));
                GetPalindrome(dp, j + 1, len, path, s);
                path.pop_back();
            }
        }
    }
};