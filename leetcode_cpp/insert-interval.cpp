/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> new_intervals;
        if (intervals.size() == 0) {  // when null
            new_intervals.push_back(newInterval);
            return new_intervals;
        }
        Interval _empty(-9999, 0);  // 真空地带
        for (int i = 0; i < intervals.size(); i++) {
            Interval& cur = intervals[i];
            _empty.end = cur.start - 1;
            if (newInterval.end < cur.start || newInterval.start > cur.end) {  // 无交集
                if (newInterval.start >= _empty.start && newInterval.end <= _empty.end) {
                    new_intervals.push_back(newInterval);
                }
                new_intervals.push_back(cur);
                _empty.start = cur.end + 1;
            } else {   // 有交集
                if (cur.start < newInterval.start) {
                    newInterval.start = cur.start;
                }
                if (cur.end > newInterval.end) {
                    newInterval.end = cur.end;
                }
            }
        }
        if (new_intervals.size() == 0 || newInterval.start > (new_intervals.end() - 1)->end) {
            new_intervals.push_back(newInterval);
        }
        return new_intervals;
    }
};