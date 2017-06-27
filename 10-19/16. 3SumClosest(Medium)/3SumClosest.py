# -*- coding: utf-8 -*-
# @Time    : 2017/6/26 上午11:21
# @Author  : fj
# @Site    : 
# @File    : 3SumClosest.py
# @Software: PyCharm

# Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
# Return the sum of the three integers. You may assume that each input would have exactly one solution.
#
# For example, given array S = {-1 2 1 -4}, and target = 1.
#
# The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)):
            j, k = i + 1, len(nums) - 1
            while j < k:
                value = nums[i] + nums[j] + nums[k]
                closest = value if abs(target - value) < abs(target - closest) else closest
                if value == target:
                    return target
                elif value > target:
                    k -= 1
                else:
                    j += 1
        return closest






a = Solution().threeSumClosest([-1, 2, 1, -4], 1)
print(a)