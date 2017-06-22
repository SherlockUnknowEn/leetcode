# 查询两个数组的中位数

#### *Median of Two Sorted Arrays*

* There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

* **Example 1**:
```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
``` 


* **Example 2**:
```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

### 思路
1. 给定nums1给nums2，则中位数的位置一定能确定，len(nums1) + len(nums2) / 2的取整值，记为median_idx
2. 需要区分是len(nums1) + len(nums2)是奇数还是偶数
3. 两个指针，只需要从nums1和nums2头部开始往后移动，将两者中较小值放入新的数组
4. 当新的数组的长度达到了median_idx，即可求中位数
5. 过程中需要注意两个数组长度不等的情况，防止下标越界
### 代码
``` python
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        median_idx = int((len(nums1) + len(nums2)) / 2)
        index1, index2 = 0, len(nums1)
        combine_list = nums1 + nums2
        new_list = []
        i = 0

        while i <= median_idx:
            if index1 < len(nums1) and index2 - len(nums1) < len(nums2):
                new_list.append(min(combine_list[index1], combine_list[index2]))
                if combine_list[index1] < combine_list[index2]:
                    index1 += 1
                else:
                    index2 += 1
            elif index1 >= len(nums1):
                # nums1 is out of range, append nums2
                new_list.append(combine_list[index2])
                index2 += 1
            elif index2 >= len(nums2):
                # nums2 is out of range, append nums1
                new_list.append(combine_list[index1])
                index1 += 1
            i += 1

        if (len(nums1) + len(nums2)) % 2 == 0:
            median = float(new_list[median_idx] + new_list[median_idx - 1]) / 2
        else:
            median = new_list[median_idx]

        return median
```
