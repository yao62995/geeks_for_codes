class Solution {
public:
    vector<vector<int> > result;

    vector<vector<int> > permuteUnique(vector<int> &num) {
        if (num.size() == 0) {
            return result;
        }
        perm(0, num);   
        return result;
    }

    void perm(int n, vector<int>& num) {
        static vector<int> pvect;
        int i, j;
        bool flag = false;
        for (i = n; i < num.size(); i++) {
            for (j = n + 1; j < i; j++) {
                if (num[j] == num[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                flag = false;
                continue;
            }
            if (i == n || num[i] != num[n]) {
                swap(num, i, n);
                pvect.push_back(num[n]);
                if ((n + 1) < num.size()) {
                    perm(n + 1, num);
                } else {
                    result.push_back(pvect);
                }
                swap(num, i, n);
                pvect.erase(pvect.end() - 1);
            }
        }
    }

    void swap(vector<int>&num, int i, int j) {
        if (i != j) {
            int tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
        }
    }
};