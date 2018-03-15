# -*- coding: utf-8 -*-
# @Time    : 2018/03/14 下午19:40
# @Author  : fj
# @Site    :
# @File    : Search Insert Position.py
# @Software: PyCharm


# Given a sorted array and a target value, return the index if the target is found.
# If not, return the index where it would be if it were inserted in order.
# You may assume no duplicates in the array

# Example 1:
# Input: [1,3,5,6], 5
# Output: 2

# Example 2:
# Input: [1,3,5,6], 2
# Output: 1

# Example 3:
# Input: [1,3,5,6], 7
# Output: 4

# Example 1:
# Input: [1,3,5,6], 0
# Output: 0

class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        # left == right 时对left做最后的处理，然后返回left
        while left <= right:
            middle = (left + right) // 2
            if nums[middle] == target:
                return middle
            elif nums[middle] < target:
                left = middle + 1
            else:
                right = middle - 1
        return left


a = Solution().searchInsert([1,3,5,6], 5)
b = Solution().searchInsert([1,3,5,6], 2)
c = Solution().searchInsert([1,3,5,6], 7)
d = Solution().searchInsert([1,3,5,6], 0)
print(a)
print(b)
print(c)
print(d)
