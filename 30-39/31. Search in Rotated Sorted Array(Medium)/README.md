# 反转内数组搜寻元素

#### *Search in Rotated Sorted Array*

* 给定一个已升序排序好的数组，数组元素不重复，但是数组从某个未知的位置旋转了。如`[0 1 2 4 5 6 7] 旋转为 [4 5 6 7 0 1 2]`。
* 给定一个数为`target`，在数组内找寻target的位置，`target`不在数组内则返回-1

题目原文:

* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* ou are given a target value to search. If found in the array return its index, otherwise return -1.
* You may assume no duplicate exists in the array.


**example 1**

```
nums: [4, 5, 6, 7, 0, 1, 2], target: 2
return: 6
```

**example 2**

```
nums: [], target: 5
return: -1
```


---

### 思路

1. 遍历数组，找到反转的位置
2. 从反转的位置分为两部分，两部分因为已经是排好序的元素，使用二分法查找



### 代码
```
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
        re = self.__barnary_search(nums, target, 0, idx)
        if re == -1:
            re = self.__barnary_search(nums, target, idx+1, len(nums)-1)
        return re



    def __barnary_search(self, nums, target, left, right):
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