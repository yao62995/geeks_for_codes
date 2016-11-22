class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        int size = num.size();
        if (size < 3) {
            return result;
        }
        sort(num.begin(), num.end());
        if (num[0] > 0 || num[size - 1] < 0) {
            return result;
        }
        int i, j;
        vector<int> triplet;
        triplet.resize(3);
        for (i = 0; i < size; i++) {
            int val = num[i];
            if (val > 0) {
                break;
            }
            if (i > 0 && val == num[i - 1]) {
                continue;
            }
            int begin, end, target;
            begin = i + 1;
            end = size - 1;
            target = 0 - val;
            while (begin < end) {
                if (begin > (i + 1) && num[begin] == num[begin - 1]) {
                    begin++;
                    continue;
                }
                if (end < (size - 1) && num[end] == num[end + 1]) {
                    end--;
                    continue;
                }
                int added = num[begin] + num[end];
                if (added > target) {
                    end--;
                } else if (added < target) {
                    begin++;
                } else {
                    triplet[0] = val;
                    triplet[1] = num[begin];
                    triplet[2] = num[end];
                    result.push_back(triplet);
                    begin++;
                    end--;
                }
            }
        }
        return result;
    }
};