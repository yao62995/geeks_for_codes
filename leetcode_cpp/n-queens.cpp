class Solution {
public:
    vector<vector<string> > result;

    vector<vector<string> > solveNQueens(int n) {
        int i, j;
        if (n == 0) {
            return result;
        }
        string _init;
        for (j = 0; j < n; j++) {
            _init.push_back('.');
        }
        vector<string> board;
        for (i = 0; i < n; i++) {
            board.push_back(_init);
        }

        _solve(0, board, n);

        return result;
    }

    void _solve(int row, vector<string>& board, int n) {
        int col;
        for (col = 0; col < n; col++) {
            board[row][col] = 'Q';
            if (_check(row, board, col)) {
                if (row == (n - 1)) {
                    result.push_back(board);
                } else {
                    _solve(row + 1, board, n);
                }
            }
            board[row][col] = '.';
        }
    }

    // no same line, no same column, no same diamond
    bool _check(int row, vector<string>& board, int col) {
        int i, j;
        int size = board.size();
        // check column
        for (i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // check diamond
        for (i = row - 1, j = 1; i >= 0; i--, j++) {
            if ((col + j) < size && board[i][col + j] == 'Q') {
                return false;
            }
            if ((col -j) >= 0 && board[i][col - j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};