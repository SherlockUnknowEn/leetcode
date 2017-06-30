# -*- coding: utf-8 -*-
# @Time    : 2017/6/30 上午9:59
# @Author  : fj
# @Site    : 
# @File    : 4Sum.py
# @Software: PyCharm


# 给定一个数组，选择四个元素相加，结果为target，找出所有符合的四元组。
# Given an array S of n integers, are there elements a, b, c,
# and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
#
# Note: The solution set must not contain duplicate triplets.

# For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
#
# A solution set is:
# [
#   [-1,  0, 0, 1],
#   [-2, -1, 1, 2],
#   [-2,  0, 0, 2]
# ]

class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        ret = []
        for i in range(len(nums) - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range (i+1, len(nums) - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                head, tail = j+1, len(nums) - 1
                while head < tail:
                    if nums[i] + nums[j] + nums[head] + nums[tail] == target:
                        ret.append([nums[i], nums[j], nums[head], nums[tail]])
                        head += 1
                        tail -= 1
                        while head < tail and nums[head] == nums[head - 1]:
                            head += 1
                        while head < tail and nums[tail] == nums[tail + 1]:
                            tail -= 1
                    elif nums[i] + nums[j] + nums[head] + nums[tail] > target:
                        tail -= 1
                    else:
                        head += 1
        return ret

a = Solution().fourSum([-1,0,1,2,-1,-4], -1)
print(a)