class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() <= 1) {
            return 0;
        }
        int begin, end, max_area;
        begin = 0;
        end = height.size() - 1;
        max_area = 0;
        int area;
        while (begin < end) {
            if (height[begin] < height[end]) {
                area = (end - begin) * height[begin];
                begin++;
            } else {
                area = (end - begin) * height[end];
                end--;
            }
            if (area > max_area) {
                max_area = area;
            }
        }
        return max_area;
    }
};