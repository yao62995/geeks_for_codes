class Solution {
public:
    string longestPalindrome(string s) {
        string ns;
        int i;
        int max_len, max_pos;
        ns.push_back('$');
        ns.push_back('#');
        for (i = 0; i < s.length(); i++) {
            ns.push_back(s[i]);
            ns.push_back('#');
        }
        int mx = 0;
        int id = 0;
        int *pid = (int *)malloc(sizeof(int) * ns.length());
        max_len = 1;
        max_pos = 0;
        for (i = 1; i < ns.length(); i++) {
            if (mx > i) {
                pid[i] = _min(pid[2 * id - i], id + pid[id] - i);
            } else {
                pid[i] = 1;
            }
            for (; ns[i + pid[i]] == ns[i - pid[i]]; pid[i]++);
            if (max_len < pid[i]) {
                max_len = pid[i];
                max_pos = i;
            }
            if ((i + pid[i]) > mx) {
                mx = i + pid[i];
                id = i;
            }
        }
        string result;
        bool odded = true;
        if (ns[max_pos] == '#') {
            odded = false;
        }
        max_len /= 2;
        max_pos = (max_pos - 2) / 2;
        if (!odded) {
            result = s.substr(max_pos - max_len + 1, max_len * 2);
        } else {
            result = s.substr(max_pos - max_len + 1, max_len * 2 - 1);
        }
        free(pid);
        return result;
    }

    int _min(int a, int b) {
        return a < b ? a : b;
    }
};