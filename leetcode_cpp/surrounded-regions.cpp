class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        set<int> sign;
        int row = board.size();
        int col = board[0].size();
        int i, j;
        // go
        vector<int> queue_pos;
        set<int> queue_set;
        bool surrounded;
        for (i = 1; i < (row - 1); i++) {
            for (j = 1; j < (col - 1); j++) {
                if (board[i][j] == 'O' && sign.find(i * col + j) == sign.end()) {
                    queue_pos.push_back(i * col + j);
                    queue_set.insert(i * col + j);
                    surrounded = true;
                    BFS(board, queue_pos, queue_set, surrounded);
                    int r, c,  k;
                    if (surrounded) {  // set 'O' to 'X'
                        for (k = 0; k < queue_pos.size(); k++) {
                            r = queue_pos[k] / col;
                            c = queue_pos[k] % col;
                            board[r][c] = 'X';
                        }
                    } else {  // set sign
                        for (k = 0; k < queue_pos.size(); k++) {
                            r = queue_pos[k] / col;
                            c = queue_pos[k] % col;
                            sign.insert(queue_pos[k]);
                        }
                    }
                    queue_pos.clear();
                    queue_set.clear();
                }
            }
        }
    }

    void BFS(vector<vector<char> > &board, vector<int> &queue_pos, set<int> &queue_set, bool &surrounded) {
        static int offset[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int index = 0;
        int row = board.size();
        int col = board[0].size();
        int i, r, c, ni, nr, nc;
        while (index < queue_pos.size()) {
            r = queue_pos[index] / col;
            c = queue_pos[index] % col;
            for (i = 0; i < 4; i++) {
                nr = r + offset[i][0];
                nc = c + offset[i][1];
                ni = nr * col + nc;
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && board[nr][nc] == 'O' && queue_set.find(ni) == queue_set.end()) {
                    queue_pos.push_back(ni);
                    queue_set.insert(ni);
                    if (nr == 0 || nr == (row - 1) || nc == 0 || nc == (col - 1)) {
                        surrounded = false;
                    }
                }
            }
            index++;
        }
    }
};