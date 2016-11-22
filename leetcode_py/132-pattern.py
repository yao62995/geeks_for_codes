class Solution(object):
    def _find132pattern(self, nums, st, ed):
        if st < (ed - 1):
            if nums[st] < nums[ed]:
                mid = st + 1
                while mid < ed:
                    if nums[mid] > nums[st] and nums[mid] > nums[ed]:
                        return True
                    mid += 1
            mst = st + 1
            while mst < (ed - 1) and nums[mst] >= nums[st]:
                mst += 1
            if self._find132pattern(nums, mst, ed):
                return True
            med = ed - 1
            while st < (med - 1) and nums[med] <= nums[ed]:
                med -= 1
            if self._find132pattern(nums, st, med):
                return True
        return False

    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return self._find132pattern(nums, 0, len(nums) - 1)