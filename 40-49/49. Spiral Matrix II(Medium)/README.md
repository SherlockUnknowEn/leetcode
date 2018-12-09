# 螺旋矩阵II

#### *Spiral Matrix II*

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。


英文题目:

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.


**example 1**

```
Input: 3
Output:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
```


---

### 思路

1. 思路参照 [Spiral Matrix](https://github.com/SherlockUnknowEn/leetcode/tree/master/40-49/46.%20Spiral%20Matrix(Medium))，按照右 -> 下 -> 左 ->上顺序走完外圈后，循环此过程


### 代码
```

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result;
		for (int i = 0; i < n; ++i)
			result.push_back(vector<int>(n));

		int i = 0, j = -1;
		int num = 1;
		while (n > 0)
		{
			//循环插值
			for (int x = 0; x < n; ++x) //go right 需要走n步
				result[i][++j] = num++;

			for (int x = 0; x < n - 1; ++x) //go down 需要走n-1步
				result[++i][j] = num++;

			for (int x = 0; x < n - 1; ++x) //go left 需要走n-1步
				result[i][--j] = num++;

			for (int x = 0; x < n - 2; ++x) //go up 需要走n-2步
				result[--i][j] = num++;

			n -= 2;
		}
		return result;
	}
};

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)