class Solution {
public:
    int totalNQueens(int n) {
        vector<int> path;
        path.resize(n + 1);
        int count = 0;
        _solve(1, path, count);
        return count;
    }

    void _solve(int row, vector<int> &path, int &count) {
        int i;
        for (i = 1; i < path.size(); i++) {
            path[row] = i;
            if (_check(row, path)) {
                if (row == (path.size() - 1)) {
                    count++;
                } else {
                    _solve(row + 1, path, count);
                }
            }
        }
    }

    bool _check(int row, vector<int> &path) {
        int i, j;
        // check col
        for (i = 1; i < row; i++) {
            if (path[i] == path[row]) {
                return false;
            }
        }
        // check diamond
        for (i = row - 1, j = 1; i >= 1; i--, j++) {
            if (path[i] == (path[row] + j) || path[i] == (path[row] - j)) {
                return false;
            }
        }
        return true;
    }
};