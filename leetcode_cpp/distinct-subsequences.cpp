class Solution {
public:
    int m_count;

    int numDistinct(string S, string T) {
        m_count = 0;
        move(S, T, 0, 0);
        return m_count;
    }

    void move(string &S, string &T, int pos_S, int pos_T) {
        int i;
        for (i = pos_S; (S.length() - i) >= (T.length() - pos_T); i++) {
            if (S[i] == T[pos_T]) {
                if (pos_T == (T.length() - 1)) {
                    m_count++;
                    return;
                }
                move(S, T, i + 1, pos_T + 1);
            }
        }
    }
};