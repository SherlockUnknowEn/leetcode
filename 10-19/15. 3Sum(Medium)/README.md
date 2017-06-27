# 三元组相加获得target
#### *3Sum*

* 给定一个数组，选择三个元素相加，结果为target，找出所有符合的三元组
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0
* Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4]

**example 1**
```
input: [-1, 0, 1, 2, -1, -4]
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

### 思路
1. 乱序数组，需要找到所有组合，需要三层循环，复杂度为O(n³)。
2. 可以先排序，排序后只需要两层循环，复杂度为O(n²)。第一层循环遍历所有元素，第二层循环由于数组已经排序，只需要头尾两个指针像中间靠拢，一但三个元素相加为target，则添加此三元组，然后继续像中间靠拢扫描。
3. 需要避免重复的三元组被加入

### 代码
```
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        ret = []
        for i in range(len(nums) - 2):
            # 避免重复
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j, k = i + 1, len(nums) - 1
            while j < k:
                if nums[i] + nums[j] + nums[k] == 0:
                    ret.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    # 避免重复
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
                elif nums[i] + nums[j] + nums[k] < 0:
                    j += 1
                else:
                    k -= 1
        return ret
```