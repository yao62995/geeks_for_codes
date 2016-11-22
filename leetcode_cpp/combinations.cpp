class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (n == 0 || k > n) {
            return result;
        }
        vector<unsigned char> mask;
        int i, j;
        for (i = 0; i < k; i++) {
            mask.push_back(1);
        }
        for (; i < n; i++) {
            mask.push_back(0);
        }
        int is_finished = false;
        vector<int> subvect;
        subvect.resize(k);
        while (!is_finished) {
            for (i = 0, j = 0; i < n && j < k; i++) {
                if (mask[i] == 1) {
                    subvect[j++] = i + 1;
                }
            }
            result.push_back(subvect);
            is_finished = true;
            for (i = 0; i < (n - 1); i++) {
                if (mask[i] == 0 || mask[i + 1] == 1) {
                    continue;
                }
                if (mask[i] == 1 && mask[i + 1] == 0) {
                    mask[i] = 0;
                    mask[i + 1] = 1;
                }
                int begin, end;
                begin = 0;
                end = i - 1;
                while (begin < end) {
                    if (mask[begin] == 1) {
                        begin++;
                        continue;
                    }
                    if (mask[end] == 0) {
                        end--;
                        continue;
                    }
                    mask[begin++] = 1;
                    mask[end--] = 0;
                }
                is_finished = false;
                break;
            }
        }
        return result;
    }
};