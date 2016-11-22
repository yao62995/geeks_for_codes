class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int i;
        if (*p == '\0') {
            return (*s == '\0');
        }
        if (*p == '.') {
            if (*(p + 1) == '*') {  // case '.*'
                for (i = 0; *(s + i) != '\0'; i++) { 
                    if (isMatch(s + i, p + 2)) {
                        return true;
                    }
                }
                return isMatch(s + i, p + 2);
            } else {
                if (*s == '\0') return false;
                return isMatch(s + 1, p + 1);
            }
        } else {
            if (*(p + 1) == '*') {  // case 'a*'
                for (i = 0; *(s + i) != '\0' && *(s + i) == *p; i++) {
                    if (isMatch(s + i, p + 2)) {
                        return true;
                    }
                }
                return isMatch(s + i, p + 2);
            } else {
                if (*p == *s) {
                    return isMatch(s + 1, p + 1);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};