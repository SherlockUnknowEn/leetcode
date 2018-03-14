# -*- coding: utf-8 -*-
# @Time    : 2018/03/14 下午17:09
# @Author  : fj
# @Site    :
# @File    : Search for a Range.py
# @Software: PyCharm


# Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# If the target is not found in the array, return [-1, -1].
#
# For example,
# Given [5, 7, 7, 8, 8, 10] and target value 8,
# return [3, 4].

class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        idx = self.__barnary_search(nums, target)
        if idx == -1:
            return [-1, -1]
        left = right = idx
        while(left >= 0 and nums[left] == target):
            left -= 1
        # 第一个元素为target的情况
        left = 0 if left == 0 and nums[left] == target else left + 1
        while(right < len(nums) and nums[right] == target):
            right += 1
        # 最后一个元素为target的情况
        right = len(nums) - 1 if right == len(nums) - 1 and nums[right] == target else right - 1
        return [left, right]



    def __barnary_search(self, nums, target):
        left = 0
        right = len(nums) - 1
        while(left <= right):
            middle = (left + right) // 2
            if nums[middle] == target:
                return middle
            elif nums[middle] > target:
                right = middle - 1
            else:
                left = middle + 1
        return -1

a = Solution().searchRange([5, 7, 7, 8, 8, 10], 8)
print(a)
print(Solution().searchRange([], 7))