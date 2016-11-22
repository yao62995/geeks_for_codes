class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if (len == 0) {
            return true;
        }
        stack<char> _stack;
        map<char, char> _map;
        _map['}'] = '{';
        _map[']'] = '[';
        _map[')'] = '(';
        int i;
        for (i = 0; i < s.size(); i++) {
            char val = s[i];
            if (val == '{' || val == '[' || val == '(') {
                _stack.push(val);
            } else {
                if (_stack.empty() || _stack.top() != _map[val]) {
                    return false;
                }
                _stack.pop();
            }
        }
        if (_stack.empty()) {
            return true;
        }
        return false;
    }
};