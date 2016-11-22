class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (row == 0) {   // case []
            return 0;
        }
        int col = matrix[0].size();
        if (col == 0) {   // case [[]]
            return 0;
        }
        vector<int> height;
        height.resize(col, 0);
        int i, j, max = 0;
        for (i = 0; i < row; i++) {
            vector<char>& line = matrix[i];
            for (j = 0; j < col; j++) {
                if (line[j] == '0') {
                    height[j] = 0;
                } else {
                    height[j] += 1;
                }
            }
            int _max = largestRectangleArea(height);
            if (_max > max) {
                max = _max;
            }
        }
        return max;
    }

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