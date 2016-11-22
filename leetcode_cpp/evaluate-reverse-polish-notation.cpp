class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int size = tokens.size();
        if (size == 0) {
            return 0;
        }
        stack<int> _stack;
        int num1, num2, num3, op;
        int i;
        for (i = 0; i < size; i++) {
            string& token = tokens[i];
            if (token.size() == 1 && !isdigit(token[0])) {
                if (_stack.size() < 2) {  // invalid tokens
                    return 0;
                }
                num2 = _stack.top();
                _stack.pop();
                num1 = _stack.top();
                _stack.pop();
                char op = token[0];
                if (op == '+') {
                    num3 = num1 + num2;
                } else if (op == '-') {
                    num3 = num1 - num2;
                } else if (op == '*') {
                    num3 = num1 * num2;
                } else if (op == '/') {
                    num3 = num1 / num2;
                }
                _stack.push(num3);
            } else {
                int val = atoi(token.c_str());
                _stack.push(val);
            }
        }
        if (_stack.size() > 1) {  // invalid tokens
            return 0;
        }
        int result = _stack.top();
        return result;
    }
};