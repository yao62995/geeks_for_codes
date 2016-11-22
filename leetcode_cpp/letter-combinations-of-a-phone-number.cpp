class Solution {
public:
    vector<string> result;

    vector<string> letterCombinations(string digits) {
        string path;
        path.resize(digits.size());
        letterCombine(digits, 0, path, 0);
        return result;
    }

    void letterCombine(string &digits, int pos, string& path, int pos2) {
        static string map_letters[10] = {"", "", "abc", "def",
                                         "ghi", "jkl", "mno",
                                         "pqrs", "tuv", "wxyz"};
        while (pos < digits.length() && digits[pos] < '2' || digits[pos] > '9') {
            pos++;
        }
        if (pos >= digits.length()) {
            result.push_back(path.substr(0, pos2));
            return;
        }
        int i, digit;
        digit = digits[pos] - '0';
        for (i = 0; i < map_letters[digit].length(); i++) {
            path[pos2] = map_letters[digit][i];
            letterCombine(digits, pos + 1, path, pos2 + 1);
        }
    }
};