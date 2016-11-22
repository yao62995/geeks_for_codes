class Solution {
public:
    vector<vector<int> > res;

    vector<vector<int> > permute(vector<int> &num) {
        if (num.size() == 0) {
            return res;
        }
        perm(0, num);
        return res;
    }

    void perm(int n, vector<int> &num) {
        static vector<int> pvect;
        int i;
        for (i = n; i < num.size(); i++) {
            swap(num, i, n);
            pvect.push_back(num[n]);
            if ((n + 1) < num.size()) {
                perm(n + 1, num);
            } else {
                res.push_back(pvect);
            }
            swap(num, i, n);
            pvect.erase(pvect.end() - 1);
        }
    }

    void swap(vector<int> &num, int i, int j) {
        if (i != j) {
            int tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
        }
    }
};