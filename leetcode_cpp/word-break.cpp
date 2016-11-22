class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int *f = (int *)malloc(sizeof(int) * s.length() * s.length());
        memset(f, 0, sizeof(int) * s.length() * s.length());
        bool res = _check(s, dict, 0, s.length() - 1, f);
        free(f);
        return res;
    }

    bool _check(string &s, unordered_set<string> &dict, int begin, int end, int *f) {
        if (f[begin * s.length() + end] == 1) {
            return true;
        }
        if (f[begin * s.length() + end] == -1) {
            return false;
        }
        if (dict.find(s.substr(begin, end - begin + 1)) != dict.end()) {
            f[begin * s.length() + end] = 1;
            return true;
        }
        int k;
        for (k = begin; k < end; k++) {
            if (_check(s, dict, begin, k, f) && _check(s, dict, k + 1, end, f)) {
                f[begin * s.length() + end] = 1;
                return true;
            }
        }
        f[begin * s.length() + end] = -1;
        return false;
    }
};