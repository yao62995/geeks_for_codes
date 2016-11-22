class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        int* paths = (int *)malloc(sizeof(int) * m * n);
        memset(paths, 0, sizeof(int) * m * n);
        int i, j;
        for (j = 1; j < n; j++) {
            paths[j] = 1;
        }
        for (i = 1; i < m; i++) {
            paths[i * n] = 1;
        }
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                paths[i * n + j] = paths[(i - 1) * n + j] + paths[i * n + (j - 1)];
            }
        }
        int maximum = paths[m * n - 1];
        free(paths);
        return maximum;
    }
};