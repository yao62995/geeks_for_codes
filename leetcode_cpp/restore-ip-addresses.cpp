class Solution {
public:
    vector<string> result;
    int path[4];

    vector<string> restoreIpAddresses(string s) {
        memset(path, 0, 4);
        _partition(s, 0, 1);
        return result;
    }

    // k (0~3)
    void _partition(string& s, int pos, int k) {
        if (pos >= s.length()) {
            return;
        } else if (k == 4) {
            if ((pos + 2) < (s.length() - 1)) {
                return;
            }
            if (pos == (s.length() - 1) && s[pos] == '0') {  // end with '0'
                format(s, path);
            } else if (s[pos] != '0' && atoi(s.substr(pos).c_str()) < 256) {
                format(s, path);
            }
            return;
        }
        if (s[pos] == '0') {
            path[k] = pos;
            _partition(s, pos + 1, k + 1);
        } else {
            path[k] = pos;
            _partition(s, pos + 1, k + 1);
            path[k] = pos + 1;
            _partition(s, pos + 2, k + 1);
            if (atoi(s.substr(pos, 3).c_str()) < 256) {
                path[k] = pos + 2;
                _partition(s, pos + 3, k + 1);
            }
        }
    }

    void format(string& s, int path[]) {
        int i, pos;
        string ns;
        pos = 0;
        for (i = 1; i < 4; i++) {
            while (pos <= path[i]) {
                ns.push_back(s[pos++]);
            }
            ns.push_back('.');
        }
        while (pos < s.length()) {
            ns.push_back(s[pos++]);
        }
        result.push_back(ns);
    }
};