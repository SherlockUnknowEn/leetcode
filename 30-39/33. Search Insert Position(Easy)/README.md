# 查找元素插入的位置

#### *Search Insert Position*

* 给定一个已升序排序好的数组，数组内没有重复元素。
* 给定一个数为`target`，如果数组存在`target`，返回它的位置，如果不存在，将它插入数组的位置返回

题目原文:

* Given a sorted array and a target value, return the index if the target is found. 
* If not, return the index where it would be if it were inserted in order.
* You may assume no duplicates in the array.


**example 1**

```
Input: [1,3,5,6], 5
Output: 2
```

**example 2**

```
Input: [1,3,5,6], 2
Output: 1
```

**example 3**

```
Input: [1,3,5,6], 7
Output: 4
```

**example 4**

```
Input: [1,3,5,6], 0
Output: 0
```


---

### 思路

1. 二分法查找
2. 当`left == right`时，若`num[left] < target`，则插入的位置为`left + 1`，若`num[left] > target`，则插入的位置为`left`，而这两步正好可以合并到二分查找的while循环中



### 代码
```
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
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)