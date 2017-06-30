# 三元组相加获得结果最接近target
#### *3SumClosest*

* 给定一个数组，选择三个元素相加，结果必须为所有三元组中最接近target的值，返回这个三元组的和。
* Given an array S of n integers, find three integers in S such that the sum is closest to a given number: target.
* Return the sum of the three integers. You may assume that each input would have exactly one solution.


**example 1**
```
For example, given array S = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

input: [-1, 2, 1, -4], 1
output: 2
```

### 思路
1. 思路参照[三元组相加获得target](https://github.com/SherlockUnknowEn/leetcode/tree/master/10-19/15.%203Sum(Medium))
2. 只需要将上述文章思路2中换成：第二次循环找到 三元组的和 最接近target的组合即可。

### 代码
```
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)):
            j, k = i + 1, len(nums) - 1
            while j < k:
                value = nums[i] + nums[j] + nums[k]
                closest = value if abs(target - value) < abs(target - closest) else closest
                if value == target:
                    return target
                elif value > target:
                    k -= 1
                else:
                    j += 1
        return closest
```