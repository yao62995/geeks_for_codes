class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int MAX = 100;
        char stack[MAX];
        int top = 0;
        for (int i = s.size() -1; i >=0; i--) {
            while (s[i] == ' ') i--;
            if (i < 0) {
                break;
            }
            while (s[i] != ' ' && i >= 0) {
                stack[top++] = s[i--];
            }
            while (top > 0) {
                res.push_back(stack[--top]);
            }
            res.push_back(' ');
            if (i < 0) {
                break;
            }
        }
        if (res[res.size() - 1] == ' ') {
            s.assign(res.begin(), res.end() - 1);
        } else {
            s.assign(res.begin(), res.end());
        }
    }
};