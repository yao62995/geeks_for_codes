class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        row_num, col_num = len(matrix), len(matrix[0])
        for row in xrange(row_num - 1, -1, -1):
            col = row_num - 1 - row
            if col < 0 or col >= col_num:
                break
            if target == matrix[row][col]:
                return True
            elif target > matrix[row][col]:
                # search matrix[row][col+1, ... N]
                begin, end = col + 1, col_num - 1
                while begin <= end:
                    mid = int((begin + end) / 2)
                    if target > matrix[row][mid]:
                        begin = mid + 1
                    elif target < matrix[row][mid]:
                        end = mid - 1
                    else:
                        return True
            else:
                # search matrix[0,...,row-1][col]
                begin, end = 0, row - 1
                while begin <= end:
                    mid = int((begin + end) / 2)
                    if target > matrix[mid][col]:
                        begin = mid + 1
                    elif target < matrix[mid][col]:
                        end = mid - 1
                    else:
                        return True
        return False