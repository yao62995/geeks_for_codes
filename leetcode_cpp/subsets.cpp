class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        sort(S.begin(), S.end());
        int i, j;
        vector<int> sub;
        result.push_back(sub);
        for (i = 0; i < S.size(); i++) {
            int new_elem = S[i];
            int cur_size = result.size();
            // result.resize(cur_size * 2);
            for (j = 0; j < cur_size; j++) {
                result.push_back(result[j]);
                result[j + cur_size].push_back(new_elem);
            }
        }
        return result;
    }
};