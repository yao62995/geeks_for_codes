class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string store[10];
        string result;
        int i, j, digit, caps;
        for (i = num2.length() - 1, caps = 0; i >= 0; i--, caps++) {
            digit = num2[i] - '0';
            if (store[digit].length() == 0) {
                _multi(num1, digit, store);
            }
            string cur = store[digit];
            for (j = 0; j < caps; j++) {
                cur.push_back('0');
            }
            add(result, cur);
        }
        return result;
    }

    void _multi(string& num1, int digit, string store[]) {
        if (digit == 0) {
            store[0].push_back('0');
        } else if (digit == 1) {
            store[1].assign(num1.begin(), num1.end());
        } else {
            int carry = 0;
            int i;
            string& num2 = store[digit];
            num2.resize(num1.length());
            for (i = num1.length() - 1; i >= 0; i--) {
                int res = (num1[i] - '0') * digit + carry;
                if (res > 9) {
                    num2[i] = res % 10 + '0';
                    carry = res / 10;
                } else {
                    num2[i] = res + '0';
                    carry = 0;
                }
            }
            if (carry > 0) {
                num2.insert(num2.begin(), carry + '0');
            }
        }
    }

    void add(string &num1, string &num2) {
        if (num1.length() == 0) {
            num1.assign(num2.begin(), num2.end());
            return;
        } else if (num2 == "0") {
            return;
        }
        if (num1.length() < num2.length()) {
            num1.insert(num1.begin(), num2.length() - num1.length(), '0');
        }
        int i, j;
        i = num1.length() - 1;
        j = num2.length() - 1;
        int carry = 0;
        for (; i >= 0 && j >= 0; i--, j--) {
            num1[i] = num1[i] + num2[j] - '0' + carry;
            if (num1[i] > '9') {
                num1[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry == 0) {
            return;
        }
        for (; i >= 0; i--) {
            num1[i] = num1[i] + carry;
            if (num1[i] <= '9') {
                return;
            } else {
                num1[i] = '0';
            }
        }
        num1.insert(num1.begin(), '1');
    }
};