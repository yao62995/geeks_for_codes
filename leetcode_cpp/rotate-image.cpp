class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 0 || n == 1) {
            return;
        }
        int i, j, k;
        int tmp;
        for (i = 0; i < (n / 2); i++) {
            for (j = i; j < (n - 1 - i); j++) {
                int cur_i = i, cur_j = j, cur_tmp;
                tmp = matrix[cur_i][cur_j];
                for (k = 0; k < 3; k++) {
                    matrix[cur_i][cur_j] = matrix[n - 1 - cur_j][cur_i];
                    cur_tmp = cur_i;
                    cur_i = n - 1 - cur_j;
                    cur_j = cur_tmp;
                }
                matrix[cur_i][cur_j] = tmp;
            }
        }
    }
};