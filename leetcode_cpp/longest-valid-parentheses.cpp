class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len <= 1) {
            return 0;
        }
        stack<int> _stack;
        int max_len = -1, cur_len = 0;
        int last_invalid_pos = -1;
        int i;
        for (i = 0; i < len; i++) {
            char ch = s[i];
            if (ch == ')') {
                if (_stack.empty()) {
                    if (max_len < cur_len) {
                        max_len = cur_len;
                    }
                    last_invalid_pos = i;
                    cur_len = 0;
                } else {
                    _stack.pop();
                    cur_len += 2;
                }
            } else {
                _stack.push(i);
            }
        }
        int begin, end;
        end = len - 1;
        while (!_stack.empty()) {  // when '(' is too much
            int begin = _stack.top();
            _stack.pop();
            if ((end - begin) > max_len) {
                max_len = end - begin;
            }
            end = begin - 1;
        }
        if ((end - last_invalid_pos) > max_len) {
            max_len = end - last_invalid_pos;
        }
        return max_len;
    }
};