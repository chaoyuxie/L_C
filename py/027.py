class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i, result = 0, len(nums)-1
        while i <= result:
            if nums[i] == val:
                nums[i], nums[result] = nums[result], nums[i]
                result -= 1
            else:
                i += 1
        return result+1
