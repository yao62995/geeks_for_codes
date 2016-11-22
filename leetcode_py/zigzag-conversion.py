class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        res = []
        for r in xrange(1, numRows + 1):
            start = r - 1
            if r in [1, numRows]:
                move_step = [2 * (numRows - 1)] * 2
            else:
                move_step = [2 * (numRows - r), 2 * (r - 1)]
            step_count = 0
            while start < len(s):
                res.append(s[start])
                start += move_step[step_count]
                step_count = (step_count + 1) & 1
        return "".join(res)
        