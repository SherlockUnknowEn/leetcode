# 数字数组的下一个最小排列

#### *Next Permutation*

* 实现数字数组的下一个最小排列，将数字重新编排成按字母顺序排列的下一个更大的数字排列。
* 如果这样的安排是不可能的，它必须重新安排它尽可能最低的顺序（即按升序排序）。

题目原文:

* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
* If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
* The replacement must be in-place, do not allocate extra memory.


**example 1**

```
1,2,3 → 1,3,2
```

**example 2**

```
3,2,1 → 1,2,3
```

**example 3**

```
1,1,5 → 1,5,1
```

**example 3**

```
[4,2,0,2,3,2,0] → [4,2,0,3,0,2,2]
```

---

### 思路

1. 从数组尾部开始遍历，查找到第一个大于其前一个元素的位置`i`，如`nums = [1, 3, 2, 1, 0]`中，`i`为1,`nums[i] > nums[i - 1]`
2. 从`i`开始往后遍历，找到最小的一个比`nums[i - 1]`大的元素，下标记为`j`，则此元素为需要和`num[i - 1]`交换的元素，如 1. 中例子， `nums[j]`为2，大于`nums[i - 1]`，交换后数组为`[2, 3, 1, 1, 0]`
3. 将`i`到`len(nums)`之间的数字从小到大排列，即可得到结构，如 1. 中例子，将`3, 1, 1, 0`从小到大排列后，最终结果为`[2, 0, 1, 1, 3]`



### 代码
```
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
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)