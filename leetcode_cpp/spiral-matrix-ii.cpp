class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        if (n == 0) {
            return result;
        }
        result.resize(n);
        int i;
        for (i = 0; i < n; i++) {
            result[i].resize(n);
        }
        _generate(result, 1, 0);
    }

    void _generate(vector<vector<int> > &matrix, int num, int k) {
        if (k > (matrix.size() - 1) / 2) {
            return;
        }
        int i, j;
        // move left to right
        int size = matrix.size() - k * 2;
        for (j = 0; j < size; j++) {
            matrix[k][k + j] = num++;
        }
        // move up to down
        for (i = 1; i < size; i++) {
            matrix[k + i][k + size - 1] = num++;
        }
        // move right to left
        for (j = size - 2; j >= 0; j--) {
            matrix[k + size - 1][k + j] = num++;
        }
        // move down to up
        for (i = size - 2; i > 0; i--) {
            matrix[k + i][k] = num++;
        }
        _generate(matrix, num, k + 1);
    }
};