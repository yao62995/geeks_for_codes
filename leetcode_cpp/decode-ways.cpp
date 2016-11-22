class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0;
        }
        // check valid
        int i;
        for (i = 1; i < s.size(); i++) {
            if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0')) {
                return 0;
            }
        }
        // calculate
        vector<int> record;
        record.resize(s.size());
        int res = numDecodings(s, 0, record);
        return res;
    }

    int numDecodings(string &s, int pos, vector<int> &record) {
        if (pos >= (s.size() - 1)) {
            record[record.size() - 1] = 1;
            return 1;
        }
        int cur = s[pos];
        int next = s[pos + 1];
        int num;
        if (next == '0') {  // skip
            num = numDecodings(s, pos + 2, record);
        } else {
            num = numDecodings(s, pos + 1, record);
            if ((pos + 2) < s.size() && s[pos + 2] == '0') {
                return num;
            }
            if (cur < '2' || (cur == '2' && next <= '6')) {
                if ((pos + 2) >= (s.size() - 1)) {
                    num++;
                } else {
                    num += record[pos + 2];
                }
            }
        }
        record[pos] = num;
        // cout << pos << " : " << num << endl;
        return num;
    }
};