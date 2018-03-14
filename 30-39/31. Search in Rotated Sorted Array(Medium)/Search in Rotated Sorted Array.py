# -*- coding: utf-8 -*-
# @Time    : 2018/03/14 上午12:00
# @Author  : fj
# @Site    :
# @File    : Search in Rotated Sorted Array.py
# @Software: PyCharm


# Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
#
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
#
# You are given a target value to search. If found in the array return its index, otherwise return -1.
#
# You may assume no duplicate exists in the array.


class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:
            return -1
        if len(nums) == 1:
            return 0 if nums[0] == target else -1
        idx = 0
        for i in range(len(nums) - 1):
            if nums[i] > nums[i+1]:
                idx = i
                break
        re = self.barnary_search(nums, target, 0, idx)
        if re == -1:
            re = self.barnary_search(nums, target, idx+1, len(nums)-1)
        return re



    def barnary_search(self, nums, target, start, end):
        if start >= end:
            if (nums[start] != target):
                return -1
            else:
                return start
        middle = (start + end) // 2
        if nums[middle] > target:
            return self.barnary_search(nums, target, start, middle)
        elif nums[middle] < target:
            return self.barnary_search(nums, target, middle+1, end)
        else:
            return middle


a = Solution().search(nums=[4, 5, 6, 7, 0, 1, 2], target=2)
b = Solution().search(nums=[], target=5)
c = Solution().search(nums=[1, 2], target=2)
d = Solution().search(nums=[2, 1], target=2)
e = Solution().search(nums=[1, 2], target=3)

print(a)
print(b)
print(c)
print(d)
print(e)
