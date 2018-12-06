# 螺旋矩阵

#### *Spiral Matrix*

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

*说明：*

你必须在原内存旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。


英文题目:

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.


**example 1**

```
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
```

**example 2**

```
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```


---

### 思路

1. 解决思路: 向右走到底，换方向向下走到底，走完一圈后，更新起始点位置和终止点位置，重复上述过程


### 代码
```

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.size() == 0)
			return result;
		int startI = 0, startJ = 0;
		int endI = matrix.size();
		int endJ = matrix[0].size();
		int i = 0,j = 0;
		while (true)
		{
			for (; j <endJ; ++j)  //向右走到尽头
				result.push_back(matrix[i][j]);
			++i;
			j = endJ - 1;
			if (!(i < endI))
				return result;

			for (; i < endI; ++i)  //向下走到尽头
				result.push_back(matrix[i][j]);
			i = endI - 1;
			--j;
			if (!(j >= startJ))
				return result;

			for (; j >= startJ; --j)  //向左走到尽头
 				result.push_back(matrix[i][j]); 
			--i; 
			j = startJ;
			if (!(i > startI))
				return result;

			for (; i > startI; --i)  //向上走到尽头
				result.push_back(matrix[i][j]);

			//尽头位置和起始位置更新
			++startI, ++startJ;
			--endI,--endJ;
			i = startI, j = startJ;

			if (startI >= endI || startJ >= endJ)
				break;
		}
		return result;
	}
};

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)