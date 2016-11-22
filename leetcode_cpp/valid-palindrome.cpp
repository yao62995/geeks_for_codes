class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) {
            return true;
        }
        string::const_iterator begin, end;
        begin = s.begin();
        end = s.end() - 1;
        // check no alphanumeric exists
        while (!isalpha(*begin) && !isdigit(*begin)) {
            begin++;
            if (begin == s.end()) {
                return true;
            }
        }

        while (begin < end) {
            while (!isalpha(*begin) && !isdigit(*begin)) {
                begin++;
            }
            while (!isalpha(*end) && !isdigit(*end)) {
                end--;
            }
            if (begin >= end) {
                break;
            }
            if (tolower(*begin) != tolower(*end)) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};