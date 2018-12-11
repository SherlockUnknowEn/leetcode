# 不同路径II

#### *Unique Paths II*

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

![loading img](https://github.com/SherlockUnknowEn/leetcode/blob/master/50-59/51.%20Unique%20Paths%20II(Medium)/robot_maze.png)


网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

英文题目:

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

**example 1**

```

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

```

---

### 思路

1. 思路参照[Unique Paths](https://github.com/SherlockUnknowEn/leetcode/tree/master/50-59/50.%20Unique%20Paths(Medium))
2. 增加判断条件：若某个网格有障碍物，则此网格可达路径为0


### 代码
```

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int>> result(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
		result[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
		for (int i = 1; i < result.size(); ++i)
		{
			//首行
			if (obstacleGrid[i - 1][0] == 1 || obstacleGrid[i][0] == 1)
				break;
			result[i][0] = 1;
		}
		for (int j = 1; j < result[0].size(); ++j)
		{
			//首列
			if (obstacleGrid[0][j - 1] == 1 || obstacleGrid[0][j] == 1)
				break;
			result[0][j] = 1;
		}
		//print(result);
		for (int i = 1; i < result.size(); ++i)
			for (int j = 1; j < result[i].size(); ++j)
				if (obstacleGrid[i][j] != 1) //无障碍
					result[i][j] = result[i - 1][j] + result[i][j - 1];
		return result[result.size() - 1][result[0].size() - 1];
	}

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)