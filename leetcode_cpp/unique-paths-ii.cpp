class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row_size, col_size;
        row_size = obstacleGrid.size();
        if (row_size == 0) {
            return 0;   // []
        }
        col_size = obstacleGrid[0].size();
        if (col_size == 0) {
            return 0;  // [[]]
        }
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row_size - 1][col_size - 1] == 1) {
            return 0;
        }
        int* paths = (int *)malloc(sizeof(int) * row_size * col_size);
        memset(paths, 0, sizeof(int) * row_size * col_size);
        int i, j;
        int no_stoped = 1;
        vector<int>& _row = obstacleGrid[0];
        for (j = 0; j < col_size; j++) {
            if (_row[j] == 1) {
                no_stoped = 0;
            }
            paths[j] = no_stoped;
        }
        no_stoped = 1;
        for (i = 1; i < row_size; i++) {
            if (obstacleGrid[i][0] == 1) {
                no_stoped = 0;
            }
            paths[i * col_size] = no_stoped;
        }
        for (i = 1; i < row_size; i++) {
            _row = obstacleGrid[i];
            for (j = 1; j < col_size; j++) {
                if (_row[j] == 1) {
                    paths[i * col_size + j] = 0;
                } else {
                    paths[i * col_size + j] = paths[(i - 1) * col_size + j] + paths[i * col_size + (j - 1)];
                }
            }
        }
        int maximum = paths[row_size * col_size - 1];
        free(paths);
        return maximum;
    }
};