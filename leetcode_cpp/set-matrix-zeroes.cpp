class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row == 0) {
            return;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return;
        }
        vector<bool> set_rows;
        vector<bool> set_cols;
        set_rows.resize(row, true);
        set_cols.resize(col, true);
        int i, j;
        for (i = 0; i < row; i++) {
            vector<int>& line = matrix[i];
            for (j = 0; j < col; j++) {
                if (line[j] == 0) {
                    set_rows[i] = false;
                    set_cols[j] = false;
                }
            }
        }
        // set zeros
        for (i = 0; i < row; i++) {
            if (!set_rows[i]) {
                for (j = 0; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (j = 0; j < col; j++) {
            if (!set_cols[j]) {
                for (i = 0; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};