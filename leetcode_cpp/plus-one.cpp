    class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int size = digits.size();
            if (size == 0) {
                return digits;
            }
            int carry = 1;
            int i;
            for (i = size - 1; i >= 0; i--) {
                digits[i] += carry;
                if (digits[i] < 10) {
                    return digits;
                } else {
                    digits[i] = 0;
                    carry = 1;
                }
            }
            // add one elements
            digits.insert(digits.begin(), 1);
            return digits;
        }
    };