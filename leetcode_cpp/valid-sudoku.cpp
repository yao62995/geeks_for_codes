
class Solution {
public:
    void bit_set(unsigned char bset[], int pos, int b_pos[]) {
        bset[pos >> 3] |= b_pos[pos - (pos >> 3 << 3)];
    }

    bool bit_test(unsigned char bset[], int pos, int b_pos[]) {
        int _pos = pos - (pos >> 3 << 3);
        return (bset[pos >> 3] & b_pos[_pos]) >> (7 - _pos);
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        //int b_pos[] = {1, 2, 4, 8, 16, 32, 64, 128};
        int b_pos[] = {128, 64, 32, 16, 8, 4, 2, 1};
        unsigned char pos[9][4];
        int i, j;
        memset(pos, 0, sizeof(unsigned char) * 9 * 4);
        int number, block;
        for (i = 0; i < 9; i++) {
            vector<char>& line = board[i];
            for (j = 0; j < 9; j++) {
                if (line[j] != '.') {
                    number = line[j] - '1';
                    block = i / 3 * 3 + j / 3;
                    if(bit_test(pos[number], i, b_pos) || bit_test(pos[number], (j + 9), b_pos)
                        || bit_test(pos[number], (block + 18), b_pos)) {
                        //cout << "invalid pos( " << (i+1) << ", " << (j+1) << " )" << endl;
                        return false;
                    }
                    bit_set(pos[number], i, b_pos);
                    bit_set(pos[number], (j + 9), b_pos);
                    bit_set(pos[number], (block + 18), b_pos);
                }
            }
        }
        return true;
    }
};