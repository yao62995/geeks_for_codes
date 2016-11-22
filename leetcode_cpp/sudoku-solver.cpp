class Solution {
public:
    vector<vector<char> >* m_board;
    vector<int> m_bit;

    void bit_set(unsigned char bset[], int pos) {
        bset[pos >> 3] |= m_bit[pos - (pos >> 3 << 3)];
    }

    void bit_unset(unsigned char bset[], int pos) {
        bset[pos >> 3] &= (~m_bit[pos - (pos >> 3 << 3)]);
    }

    bool bit_test(unsigned char bset[], int pos) {
        int _pos = pos - (pos >> 3 << 3);
        return (bset[pos >> 3] & m_bit[_pos]) >> (7 - _pos);
    }

    void solveSudoku(vector<vector<char> > &board) {
        int b_pos[] = {128, 64, 32, 16, 8, 4, 2, 1};
        m_bit.assign(b_pos, b_pos + 8);
        unsigned char pos[9][4];
        memset(pos, 0, sizeof(unsigned char) * 9 * 4);
        int number, block;
        int i, j;
        for (i = 0; i < 9; i++) {
            vector<char>& row = board[i];
            for (j = 0; j < 9; j++) {
                if (row[j] != '.') {
                    number = row[j] - '1';
                    block = i / 3 * 3 + j / 3;
                    bit_set(pos[number], i);
                    bit_set(pos[number], (j + 9));
                    bit_set(pos[number], (block + 18));
                }
            }
        }
        m_board = &board;
        _solve(pos, 0, 0);
    }

    bool _solve(unsigned char pos[][4], int row, int col) {
        if (row == 9) {
            return true;
        }
        while ((*m_board)[row][col] != '.') {
            col++;
            if (col == 9) {
                row++;
                col = 0;
            }
            if (row == 9) {  // end
                return true;
            }
        }
        int i, block;
        for (i = 0; i < 9; i++) {
            block = row / 3 * 3 + col / 3;
            if (bit_test(pos[i], row) || bit_test(pos[i], (col + 9)) || bit_test(pos[i], (block + 18))) {
                continue;
            }
            bit_set(pos[i], row);
            bit_set(pos[i], col + 9);
            bit_set(pos[i], block + 18);
            (*m_board)[row][col] = i + '1';
            if (col == 8) {
                if (_solve(pos, row + 1, 0)) {
                    return true;
                }
            } else {
                if (_solve(pos, row, col + 1)) {
                    return true;
                }
            }
            bit_unset(pos[i], row);
            bit_unset(pos[i], col + 9);
            bit_unset(pos[i], block + 18);
            (*m_board)[row][col] = '.';
        }
        return false;
    }
};