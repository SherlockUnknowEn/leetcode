# 子集

#### *Subsets*

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。


英文题目:

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

**example 1**

```
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

```

---

### 思路

1. `[1 ,2, 3]`的子集，等于`[1, 2]`的子集`s = [[], [1], [2], [1, 2]]`本身，加上子集s的每个元素与`[3]`合并
    即`[]`与`[3]`合并为`[3]`，`[1]`与`[3]`合并为`[1, 3]`


### 代码
```

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> prev = { {} };
		vector<vector<int>> combition;
		for (auto n : nums)
		{
			combition.clear();
			for (auto p : prev)
			{
				vector<int> tmp(p);
				tmp.push_back(n);
				combition.push_back(tmp);
			}
			prev.insert(prev.begin(), combition.begin(), combition.end());
		}
		return prev;
	}
};

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)