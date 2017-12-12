# -*- coding: utf-8 -*-
# @Time    : 2017/12/11 下午5:26
# @Author  : fj
# @Site    : 
# @File    : Next Permutation.py
# @Software: PyCharm

# Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
#
# If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
#
# The replacement must be in-place, do not allocate extra memory.
#
# Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
# 1,2,3 → 1,3,2
# 3,2,1 → 1,2,3
# 1,1,5 → 1,5,1
# 2,3,1 → 3,1,2
# [4,2,0,2,3,2,0] → [4,2,0,3,0,2,2]

class Solution(object):

    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        for i in reversed(range(len(nums))):
            if (nums[i] > nums[i - 1]):
                min_idx = i
                for j in range(i+1, len(nums)):
                    if nums[j] > nums[i - 1]:
                        min_idx = j
                    else:
                        break
                nums[min_idx], nums[i - 1] = nums[i-1], nums[min_idx]
                tmp = nums[i:]
                tmp.sort()
                nums[i:] = tmp
                return
        nums.sort()



a = [1, 2, 3]
b = [3, 2, 1]
c = [1, 1, 5]
d = [2, 3, 1]
te = [2, 0, 2]
e = [4,2,0,2,3,2,0]
t1 = [1, 3, 2]
t2 = [1, 3, 2, 1, 0]

te.sort()
print(te)
Solution().nextPermutation(t2)
print(t2)
