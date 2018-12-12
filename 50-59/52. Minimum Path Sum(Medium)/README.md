# 最小路径和

#### *Minimum Path Sum*

给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

英文题目:

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

**example 1**

```
Input:
[
[1,3,1],
[1,5,1],
[4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

```

---

### 思路

1. 动态规划
2. 终点的最小值，为其上一格与其左一格两者中的较小值 + 终点格子的值
3. 终点其上一格的最小值，递归上诉过程


### 代码
```

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;
		vector<vector<int>> result(grid);
		int m = result.size();
		int n = result[0].size();
		for (int i = 1; i < m; ++i)
			result[i][0] += result[i - 1][0];
		for (int j = 1; j < n; ++j)
			result[0][j] += result[0][j - 1];
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				result[i][j] = std::min(result[i - 1][j], result[i][j - 1]) + result[i][j];
		return result[m - 1][n - 1];
	}
};

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)