class Solution {
public:
    vector<vector<char> >* m_board;
    string* m_word;

    bool exist(vector<vector<char> > &board, string word) {
        int row = board.size();
        if (row == 0 || word.size() == 0) {
            return false;
        }
        m_board = &board;
        m_word = &word;
        int i, j;
        for (i = 0; i < row; i++) {
            vector<char>& line = board[i];
            for (j = 0; j < line.size(); j++) {
                if (line[j] == word[0]) {
                    if(_go(i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // board<row, col>  and  word[pos]
    bool _go(int row, int col, int pos) {
        static int offset[8] = {1, 0/*down*/, -1, 0/*up*/, 0, 1/*right*/, 0, -1/*left*/};
        static set<pair<int, int> > path;
        if (row < 0 || row >= m_board->size() || col < 0 || col >= (*m_board)[row].size()) {
            return false;
        }
        if ((*m_word)[pos] == (*m_board)[row][col]) {
            if (pos == (m_word->size() - 1)) {
                return true;
            }
            path.insert(make_pair(row, col));
            for (int i = 0; i < 8; i += 2) {
                if (path.find(make_pair(row + offset[i], col + offset[i + 1])) != path.end()) {  // visited
                    continue;
                }
                if(_go(row + offset[i], col + offset[i + 1], pos + 1)) {
                    return true;
                }
            }
            path.erase(make_pair(row, col));
        }
        return false;
    }
};