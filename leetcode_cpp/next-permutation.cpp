class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        if (size <= 1) {
            return;
        }
        int begin, end;
        end = size - 1;
        while (end > 0) {
            if (num[end] <= num[end - 1]) {
                end--;
            } else {
                int tmp;
                begin = end - 1;
                end = size - 1;
                while (num[end] <= num[begin]) {
                    end--;
                }
                swap(num, begin, end);
                begin++;
                end = size - 1;
                while (begin < end) {
                    swap(num, begin, end);
                    begin++;
                    end--;
                }
                return;
            }
        }
        // when no arrangement
        begin = 0;
        end = size - 1;
        while (begin < end) {
            swap(num, begin, end);
            begin++;
            end--;
        }
    }

    void swap(vector<int>& num, int i, int j) {
        if (i != j) {
            int tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
        }
    }
};