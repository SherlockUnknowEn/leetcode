# encoding: utf-8

'''

@author: fengjie

@contact: fjie666@outlook.com

@software: pycharm

@file: Wildcard Matching.py

@time: 2018/5/6 下午5:53


'''


# Given an unsorted integer array, find the smallest missing positive integer.
#
# Example 1:
#
# Input: [1,2,0]
# Output: 3
# Example 2:
#
# Input: [3,4,-1,1]
# Output: 2
# Example 3:
#
# Input: [7,8,9,11,12]
# Output: 1
# Note:
#
# Your algorithm should run in O(n) time and uses constant extra space.


class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # if len(nums) == 0:
        #     return 1
        # m = max(nums)
        # for x in range(1, m):
        #     if x not in nums: # in的时间复杂度为O(n) 总时间复杂度会成为(n²)
        #         return x
        # return m+1 if m+1 > 0 else 1

        if not nums:
            return 1
        for i in range(len(nums)):
            while nums[i] > 0 and nums[i] <= len(nums) and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return len(nums) + 1  # nums从1开始连续不缺失


# a = Solution().firstMissingPositive([1,2,3,4,5,6,7])
# b = Solution().firstMissingPositive([3,4,-1,1])
c = Solution().firstMissingPositive([7,8,9,11,12])
# print(a)
# print(b)
print(c)