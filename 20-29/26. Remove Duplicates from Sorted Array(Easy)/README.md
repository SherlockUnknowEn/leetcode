# 移除数组中的重复元素
#### *Remove Duplicates from Sorted Array*

* 给定一个数组，移除数组中的重复元素，返回新数组的长度，不允许开辟新的数组空间，只能在原数组内存中完成。

题目原文:

* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

* Do not allocate extra space for another array, you must do this in place with constant memory.




**example **
```
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
```

---

### 思路

1. 简单到爆，思路不写


 
### 代码
```
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        idx = 0
        for i in range(len(nums)):
            if nums[idx] != nums[i]:
                idx += 1
                nums[idx] = nums[i]
        return idx + 1
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)