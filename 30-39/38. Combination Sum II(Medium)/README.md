# 组合总数 II

#### *Combination Sum II*

给定一个数组 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。

**说明**

* `candidates` 中的每个数字在每个组合中只能使用一次。
* 解集不能包含重复的组合。 


英文题目:

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

Each number in `candidates` may only be used once in the combination.

**Note:**


* All numbers (including `target`) will be positive integers.

* The solution set must not contain duplicate combinations.


**example 1**

```
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```

**example 2**

```
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
```


---

### 思路

1. 参照相似问题 [数组总和](https://github.com/SherlockUnknowEn/leetcode/tree/master/30-39/37.%20Combination%20Sum(Medium))
2. 会产生相同解，需要剔除



### 代码
```
class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        candidates = sorted(candidates) #排序
        def combin(candidates, target, i, curr):
            if target == 0:
                result.append(list(curr))
                return
            if i >= len(candidates):
                return
            if target < 0:
                return
            if candidates[i] <= target:
                curr.append(candidates[i])
                combin(candidates, target - candidates[i], i+1, curr) # i+1 candidates中元素只可使用一次
                curr.pop()
                combin(candidates, target, i+1, curr)
            else:
                combin(candidates, target, i+1, curr)
        combin(candidates, target, 0, [])
        result = self.removeSame(result) #剔除相同解
        return result


    def removeSame(self, result):
        arr = []
        for x in result:
            d = {}
            for num in x:
                d[num] = (d[num] + 1 if num in d else 1)
            if d not in arr:
                arr.append(d)
        uni_result = []
        for d in arr:
            tmp = []
            for num, count in d.items():
                tmp.extend([num] * count)
            uni_result.append(tmp)
        return uni_result
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)