/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int i, j;
        map<float, int> map_k;
        map<float, int>::iterator map_iter;
        int max = 0;
        for (i = 0; i < points.size(); i++) {
            int duplicate = 1;
            for (j = i + 1; j < points.size(); j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                int rate;
                if (points[j].x == points[i].x) {
                    rate = numeric_limits<float>::max();
                } else {
                    rate = (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                }
                map_iter = map_k.find(rate);
                if (map_iter == map_k.end()) {
                    map_k[rate] = 1;
                } else {
                    map_k[rate]++;
                }
            }
            // find max
            for (map_iter = map_k.begin(); map_iter != map_k.end(); map_iter++) {
                if (max < (map_iter->second + duplicate)) {
                    max = map_iter->second + duplicate;
                }
            }
            if (map_k.size() == 0 && max < (duplicate)) {
                max = duplicate;
            }
            map_k.clear();
        }
        return max;
    }
};