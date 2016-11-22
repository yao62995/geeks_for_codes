class Solution {
public:
    set<pair<const string*, const string*> > dist_set;
    set<const string*> dist_end;

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end || dict.size() == 0) {
            return 0;
        }
        if (check(start, end)) {
            return 2;
        }
        // distance set, contain only (distance = 1)
        dict.insert(start);
        unordered_set<string>::iterator iter_i, iter_j;
        for (iter_i = dict.begin(); iter_i != dict.end(); iter_i++) {
            for (iter_j = iter_i, iter_j++; iter_j != dict.end(); iter_j++) {
                if (check(*iter_i, *iter_j)) {
                    dist_set.insert(make_pair(&*iter_i, &*iter_j));
                    dist_set.insert(make_pair(&*iter_j, &*iter_i));
                }
            }
            if (check(*iter_i, end)) {
                dist_end.insert(&*iter_i);
            }
        }
        if (dist_end.size() == 0) {
            return 0;
        }
        // 
        unordered_set<string>::iterator st = dict.find(start);
        int result = ladder(&*st, dict);
        return result;
    }

    int ladder(const string* start, unordered_set<string> &dict) {
        static set<const string*> path;
        if (dist_end.find(start) != dist_end.end()) {  // ended
            return 2;
        }
        path.insert(start);
        unordered_set<string>::iterator iter_i;
        int min_ladder = dict.size() + 2;
        bool flag = false;
        for (iter_i = dict.begin(); iter_i != dict.end(); iter_i++) {
            if (dist_set.find(make_pair(&*iter_i, start)) != dist_set.end() &&
                path.find(&*iter_i) == path.end()) {
                int res = ladder(&*iter_i, dict);
                if (res == 0) {  // no way to go
                    return 0;
                }
                if (res < min_ladder) {
                    min_ladder = res;
                }
                flag = true;
            }
        }
        if (!flag) {
            return 0;
        }
        path.erase(path.find(start));
        min_ladder += 1;
        return min_ladder;
    }



    // distance of two string, return true when distance=1, else return false
    bool check(const string &str1, const string &str2) {
        string::const_iterator p1, p2;
        int diff = 0;
        for (p1 = str1.begin(), p2 = str2.begin(); p1 != str1.end() && p2 != str2.end(); p1++, p2++) {
            if (*p1 != *p2) {
                diff++;
            }
            if (diff > 1) {  // distance > 1
                return false;
            }
        }
        return true;
    }
};