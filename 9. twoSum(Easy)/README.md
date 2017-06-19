# 从数组中寻找和的相加数
#### *Two Sum*

* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

* You may assume that each input would have exactly one solution, and you may not use the same element twice.

**example 1**
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
**example 2**
```
Given nums = [0,4,3,0], target = 0,

Because nums[0] + nums[3] = 0 + 0 = 0,
return [0, 3].
```
**example 3**
```
Given nums = [-1,-2,-3,-4,-5], target = -8,

Because nums[2] + nums[4] = -3 + (-5) = -8,
return [2, 4].
```
**example 4**
```
Given nums = [0,1,2,3,4,5,...,28888,...,65432], target = 65432,

you should consider that time and space is limited.
```
### 思路
1. 这个题目简单，两个for循环嵌套可以实现，但是考虑到输入数组长度大的情况下，时间复杂度太高, O(n²)
2. 使用索引，遍历一次后记录nums中所有数字出现的下标，用target - nums[i]得到j，然后直接查索引中j的位置
3. 索引可以用list(数组)，但是nums中可能会有大数字，所需的空间太多，并且会有负数，改用dir，key为nums[i]，value为i
4. 同时给出简单版代码（简单版在java，C等语言在leetcode网站可以AC，但python会超时）


### 代码
**优化版**
```
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
```
**简单版**
```
class Solution:

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return list([i, j])
```