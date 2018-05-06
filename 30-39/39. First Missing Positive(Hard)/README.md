# 缺失的第一个正数

#### *First Missing Positive*

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

**说明**

* 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。


英文题目:

Given an unsorted integer array, find the smallest missing positive integer.


**Note:**


* Your algorithm should run in O(n) time and uses constant extra space.


**example 1**

```
Input: [1,2,0]
Output: 3
```

**example 2**

```
Input: [3,4,-1,1]
Output: 2
```

**example 3**

```
Input: [7,8,9,11,12]
Output: 1
```

---

### 思路

1. 数组长度为n，找到数组最大值m，从1开始遍历到m，如果未出现在数组中，则返回此数。明显可知`m <= n`，但由于python list中的`in`时间复杂度为O(n)，若`m = n`，总时间复杂度为O(n²)，不符合
2. 遍历数组，将`nums[i]`放回其对应位置，如找到5，则令`nums[4] = 5`，最后找到nums下标不对的位置，返回i+1，思路来自discuss区



### 代码
```
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
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)