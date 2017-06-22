# -*- coding: utf-8 -*-
# @Time    : 2017/6/19 下午6:26
# @Author  : fj
# @Site    : 
# @File    : twoSum.py
# @Software: PyCharm

class Solution:

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        idx_set = {}
        for i, item in enumerate(nums):
            idx = target - nums[i]
            if idx in idx_set:
                j = idx_set[idx]
                if len(j) != 0 and j[0] != i:
                    return list([i, j[0]])
                if j[0] == i and len(j) > 1:
                    return list([i, j[1]])
            else:
                idx_set[item] = [i]

    def twoSum_simple(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return list([i, j])

print(Solution().twoSum([3,2,4], 6))
print(Solution().twoSum([-1,-2,-3,-4,-5], -8))
print(Solution().twoSum([5, 75, 25], 100))
print(Solution().twoSum([0,4,3,0], 0))