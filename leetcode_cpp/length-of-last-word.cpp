class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL) {
            return 0;
        }
        int len = strlen(s);
        const char* p = s + len - 1;
        while (*p == ' ' && p > s) {
            p--;
        }
        if (p == s && *p == ' ') {
            return 0;
        }
        int _len = 0;
        while (*p != ' ' && p >= s) {
            p--;
            _len++;
        }
        return _len;
    }
};