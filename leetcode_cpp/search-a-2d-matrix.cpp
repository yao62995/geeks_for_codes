class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[row - 1][col - 1]) {
            return false;
        }
        int target_row = BiSearch_Row(matrix, 0, row - 1, target);
        if (matrix[target_row][0] == target) {
            return true;
        }
        bool result = BiSearch_Col(matrix[target_row], 0, col - 1, target);
        return result;
    }

    int BiSearch_Row(vector<vector<int> > &matrix, int begin, int end, int target) {
        if (begin > end) {
            return begin - 1;
        }
        int middle = (begin + end) / 2;
        if (matrix[middle][0] == target) {
            return middle;
        } else if (matrix[middle][0] > target) {
            return BiSearch_Row(matrix, begin, middle - 1, target);
        } else {
            return BiSearch_Row(matrix, middle + 1, end, target);
        }
    }

    bool BiSearch_Col(vector<int> &vect, int begin, int end, int target) {
        if (begin > end) {
            return false;
        }
        int middle = (begin + end) / 2;
        if (vect[middle] == target) {
            return true;
        } else if (vect[middle] > target) {
            return BiSearch_Col(vect, begin, middle - 1, target);
        } else {
            return BiSearch_Col(vect, middle + 1, end, target);
        }
    }
};