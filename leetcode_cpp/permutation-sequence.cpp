class Solution {
public:
    string result;

    string getPermutation(int n, int k) {
        vector<int> num;
        int i, factorial = 1;
        for (i = 0; i < n; i++) {
            num.push_back(i + 1);
            factorial *= (i + 1);
        }
        k = (k - 1) % factorial;
        getFirst(num, factorial, k);
        return result;
    }

    void getFirst(vector<int> num, int factorial, int k) {
        if (k == 0) {
            format(num);
            return;
        }
        factorial /= num.size();
        result.push_back(num[k / factorial] + '0');
        num.erase(num.begin() + k / factorial);
        k = k % factorial;
        getFirst(num, factorial, k);
    }

    void format(vector<int>& num) {
        int i;
        for (i = 0; i < num.size(); i++) {
            result.push_back(num[i] + '0');
        }
    }
};