class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        contains = set()
        for n in nums:
            if n in contains:
                contains.remove(n)
            else:
                contains.add(n)
        return list(contains)