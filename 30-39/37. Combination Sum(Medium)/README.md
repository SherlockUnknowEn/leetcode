# 组合总数

#### *Combination Sum*

给定一个无重复元素的数组 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。

`candidates` 中的数字可以无限制重复被选取。

说明：

所有数字（包括 `target`）都是正整数。
解集不能包含重复的组合。 


英文题目:

* Given a set of candidate numbers (`candidates`) (**without duplicates**) and a target number (`target`), find all unique combinations in candidates where the candidate numbers sums to `target`.

* The **same** repeated number may be chosen from `candidates` unlimited number of times.

Note:

* All numbers (including `target`) will be positive integers.
* The solution set must not contain duplicate combinations.


**example 1**

```
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```

**example 2**

```
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
```


---

### 思路

1. 遍历candidates，转化为子问题fun(candidate, target - candidates[i])，如`[2, 3, 6, 7], 10`，可以先尝试curr = [2]，并转化为子问题`[2, 3, 6, 7], 8`， 递归后为curr = [2, 2]，并再次转化为子问题`[2, 3, 6, 7], 6`
2. 如遇到和不为target的，回溯



### 代码
```
class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        def combin(candidates, target, i, curr):
            if target == 0:
                result.append(list(curr)) #找到解
                return
            if i >= len(candidates):
                return
            if target < 0:
                return
            if candidates[i] <= target:
                curr.append(candidates[i])                          #尝试一个解
                combin(candidates, target - candidates[i], i, curr) #转化为子问题
                curr.pop()                                          #回溯
                combin(candidates, target, i+1, curr)               #尝试另一个解
            else:
                combin(candidates, target, i+1, curr)
        combin(candidates, target, 0, [])
        return result
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)