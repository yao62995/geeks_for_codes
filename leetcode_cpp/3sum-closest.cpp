class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        if (size < 3) {
            return 0;
        }
        int result = num[0] + num[1] + num[2];
        int closest = abs(target - result);
        
        sort(num.begin(), num.end());
        int i;
        for (i = 0; i < (size - 2); i++) {
            int val = num[i];
            if ((val + num[i + 1] + num[i + 2]) > (target + closest)) {
                break;
            }
            if (i > 0 && val == num[i - 1]) {
                continue;
            }
            int begin, end, target_min, target_max;
            begin = i + 1;
            end = size - 1;
            target_min = target - closest;
            target_max = target + closest;
            while (begin < end) {
                if (begin > (i + 1) && num[begin] == num[begin - 1]) {
                    begin++;
                    continue;
                }
                if (end < (size - 1) && num[end] == num[end + 1]) {
                    end--;
                    continue;
                }
                int added = num[begin] + num[end] + val;
                if (added >= target_max) {
                    end--;
                } else if (added <= target_min) {
                    begin++;
                } else {
                    result = added;
                    closest = abs(target - added);
                    begin++;
                    // end--;
                }
            }
        }
        return result;
    }
};