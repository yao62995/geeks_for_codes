class Solution {
public:
    int candy(vector<int> &ratings) {
        int i, j;
        int num = 1, sum = 1;
        int extra = 1, large = 99999;
        int size = ratings.size();
        for (i = 1; i < size; i++) {
            if (ratings[i] == ratings[i - 1]) {
                num = 1;
                sum += num;
                extra = 1;
                large = 99999;
            } else if (ratings[i] > ratings[i - 1]) {
                num++;
                sum += num;
                extra = 1;
                large = num;
            } else {
                if (num == 1) {  // add extra
                    sum += extra;
                    extra++;
                    if (extra >= large) {
                        sum++;
                    }
                }
                num = 1;
                sum += num;
            }
        }
        return sum;
    }
};