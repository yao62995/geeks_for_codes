class Solution {
public:
    size_t find(const string& str, char s, size_t begin, size_t end) {
        while (begin < end) {
            if (str[begin] == s) {
                return begin;
            }
            begin++;
        }
        return string::npos;
    }

    int lengthOfLongestSubstring(string s) {
        size_t begin = 0, end = 1;
        size_t max = 1;
        if (s.length() <= 1) {
            return s.length();
        }
        while (end < s.length()) {
            size_t pos = find(s, s[end], begin, end);
            if (pos == string::npos) {
                end++;
                if ((end - begin) > max) {
                    max++;
                }
            } else {
                begin = pos  + 1;
                end++;
            }
        }
        return max;
    }
};