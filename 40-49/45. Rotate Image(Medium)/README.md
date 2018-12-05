# 旋转图像

#### *Rotate Image*

给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

*说明：*

你必须在原内存旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。


英文题目:

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

*Note: *

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.


**example 1**

```
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

**example 2**

```
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```


---

### 思路

1. 解决思路1: 先转置，再水平翻转
```

[1, 2, 3],
[4, 5, 6],    ->   
[7, 8, 9]

[1, 4, 7],
[2, 5, 8],    ->
[3, 6, 9]

[7, 4, 1],
[8, 5, 2], 
[9, 6, 3]

```

2. 解决思路2: 先垂直翻转，再转置, 好处是可以用标准库std::reverse函数进行垂直翻转
```

[1, 2, 3],
[4, 5, 6],    ->   
[7, 8, 9]


[7, 8, 9],
[4, 5, 6],    ->
[1, 2, 3]

[7, 4, 1],
[8, 5, 2], 
[9, 6, 3]

```



### 代码
```

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		std::reverse(matrix.begin(), matrix.end());

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = i + 1; j < matrix.size(); j++)
			{
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)