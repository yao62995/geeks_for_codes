class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        string* lg = &a; // longer one
        string* st = &b;
        if (a.length() < b.length()) {
            lg = &b;
            st = &a;
        }
        res.resize(lg->length());
        int carry = 0;
        int i, j;
        for (i = lg->size() - 1, j = st->size() - 1; j >= 0; i--, j--) {
            res[i] = lg->at(i) + st->at(j) + carry - '0';
            if (res[i] > '1') {
                carry = 1;
                res[i] -= 2;
            } else {
                carry = 0;
            }
        }
        for (; i >= 0; i--) {
            res[i] = lg->at(i) + carry;
            if (res[i] == '2') {
                res[i] = '0';
            } else {
                carry = 0;
            }
        }
        if (carry == 1) {
            res.insert(res.begin(), '1');
        }
        return res;
    }
};