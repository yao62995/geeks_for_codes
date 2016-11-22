class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        start, end = 0, len(numbers) - 1
        while start < end:
            val = numbers[start] + numbers[end]
            if val < target:
                start += 1
            elif val > target:
                end -= 1
            else:
                return start+1, end+1