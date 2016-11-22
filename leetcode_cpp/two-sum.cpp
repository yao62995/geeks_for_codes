class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int, int> map_kv;
        map<int, int>::iterator iter;
        int i;
        for (i = 0; i < numbers.size(); i++) {
            int val = numbers[i];
            iter = map_kv.find(target - val);
            if (iter != map_kv.end()) {
                result.push_back(iter->second + 1);
                result.push_back(i + 1);
                return result;
            } else {
                map_kv.insert(make_pair(val, i));
            }
        }
        return result;
    }
};