class Solution {
public:
    vector<int> result;

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row == 0) {
            return result;
        }
        int col = matrix[0].size();
        _spiral(matrix, row, col, 0);
        return result;
    }

    void _spiral(vector<vector<int> > &matrix, int row, int col, int zero) {
        int i, j;
        if (row <= 0 || col <= 0) {
            return;
        } else if (row == 1) {
            for (j = 0; j < col; j++) {
                result.push_back(matrix[zero][zero + j]);
            }
            return;
        } else if (col == 1) {
            for (i = 0; i < row; i++) {
                result.push_back(matrix[i + zero][zero]);
            }
            return;
        }
        // move from left to right
        for (j = 0; j < col; j++) {
            result.push_back(matrix[zero][zero + j]);
        }
        // move from up to down
        for (i = 1; i < row; i++) {
            result.push_back(matrix[zero + i][zero + col - 1]);
        }
        // move from right to left
        for (j = col - 2; j >= 0; j--) {
            result.push_back(matrix[zero + row - 1][zero + j]);
        }
        // move from bottom to up
        for (i = row - 2; i > 0; i--) {
            result.push_back(matrix[zero + i][zero]);
        }
        _spiral(matrix, row - 2, col - 2, zero + 1);
    }
};