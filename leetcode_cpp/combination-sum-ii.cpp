class Solution {
public:
    vector<vector<int> > m_combines;
    vector<int> *m_candidates;

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        m_candidates = &num;
        vector<int> path;
        _combine(path, 0, target);
        return m_combines;
    }

    void _combine(vector<int> &path, int pos, int target) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            m_combines.push_back(path);
            return;
        }
        
        int i, j;
        for (i = pos; i < m_candidates->size() && m_candidates->at(i) <= target; ) {
            path.push_back(m_candidates->at(i));
            _combine(path, i + 1, target - m_candidates->at(i));
            path.pop_back();
            for (j = i + 1; j < m_candidates->size() && (m_candidates->at(j) == m_candidates->at(j - 1)); j++);
            i = j;
        } 
    }
};