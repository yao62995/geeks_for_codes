class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int h_size = height.size();
        if (h_size == 0) {
            return 0;
        }
        stack<int> value_stack;
        stack<int> index_stack;
        value_stack.push(height[0]);
        index_stack.push(0);
        int i, max = 0, rect_area;
        int last_index = 0;
        for (i = 1; i < h_size; i++) {
            if (height[i] > value_stack.top()) {
                value_stack.push(height[i]);
                index_stack.push(i);
            } else if (height[i] < value_stack.top()) {
                while (!value_stack.empty() && value_stack.top() > height[i]) {
                    last_index = index_stack.top();
                    rect_area = (value_stack.top() * (i - last_index));
                    if (rect_area > max) {
                        max = rect_area;
                    }
                    value_stack.pop();
                    index_stack.pop();
                }
                if (value_stack.empty() || value_stack.top() < height[i]) {
                    value_stack.push(height[i]);
                    index_stack.push(last_index);
                }
            }
        }
        while (!value_stack.empty()) {
            rect_area = value_stack.top() * (h_size - index_stack.top());
            if (rect_area > max) {
                max = rect_area;
            }
            value_stack.pop();
            index_stack.pop();
        }
        return max;
    }
};