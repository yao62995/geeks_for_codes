class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row_size, col_size;
        row_size = grid.size();
        if (row_size == 0) {
            return 0;    // case: []
        }
        col_size = grid[0].size();
        if (col_size == 0) {
            return 0;    // case: [[]]
        }

        int *min_grid;
        min_grid = (int *)malloc(sizeof(int) * row_size * col_size);
        memset(min_grid, 0, sizeof(int) * row_size * col_size);

        min_grid[0] = grid[0][0];
        int i, j;
        vector<int>& _row = grid[0];
        for (j = 1; j < col_size; j++) {
            min_grid[j] = min_grid[j - 1] + _row[j];
        }
        for (i = 1; i < row_size; i++) {
            min_grid[i * col_size] = min_grid[(i - 1) * col_size] + grid[i][0];
        }
        for (i = 1; i < row_size; i++) {
            _row = grid[i];
            for (j = 1; j < col_size; j++) {
                int min = min_grid[(i - 1) * col_size + j];
                if (min > min_grid[i * col_size + j - 1]) {
                    min = min_grid[i * col_size + j - 1];
                }
                min_grid[i * col_size + j] = min + _row[j];
            }
        }

        int shortest = min_grid[row_size * col_size - 1];
        free(min_grid);
        return shortest;
    }
};