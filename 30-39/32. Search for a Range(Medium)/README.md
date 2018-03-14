# 查找元素在数组中的位置范围

#### *Search for a Range*

* 给定一个已升序排序好的数组，数组内可能有重复元素。
* 给定一个数为`target`，在数组内找寻target的位置，并返回这个元素的开始位置和结束位置
* 你必须使用O(log n)的时间复杂度完成

题目原文:

* Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
* Your algorithm's runtime complexity must be in the order of O(log n).
* If the target is not found in the array, return [-1, -1].


**example 1**

```
nums: [5, 7, 7, 8, 8, 10], target: 8
return: [3, 4]
```

**example 2**

```
nums: [], target: 5
return: [-1, -1]
```


---

### 思路

1. O(log n)时间复杂度 + 已排序，可使用二分法查找
2. 查找到`target`位置后, 向前后搜寻开始位置和结束位置



### 代码
```
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
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)