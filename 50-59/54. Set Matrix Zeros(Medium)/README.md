# 矩阵置零

#### *Set Matrix Zeroes*

给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用 in-place 算法。

进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？

英文题目:

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

**example 1**

```
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

```

**example 2**

```
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

```


---

### 思路

1. 使用每一行的首位作为此行是否要置零的标记位，如果此行需要置零，则此行首位为零。
2. 使用每一列的首位作为此列是否要置零的标记位，如果此列需要置零，则此列首位为零。
3. 遍历所有元素后得到需要置零的行和列，同时需要额外两个变量保存第一行和第一列是否需要置零，因遍历时第一行和第一列已被修改过。


### 代码
```

#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false;
        bool col0 = false;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (i == 0 && matrix[i][j] == 0)
                    row0 = true;
                if (j == 0 && matrix[i][j] == 0)
                    col0 = true;
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }


        for (int i = 1; i < matrix.size(); ++i)
            if (matrix[i][0] == 0)
                for (int j = 0; j < matrix[i].size(); ++j)
                    matrix[i][j] = 0;

        for (int j = 1; j < matrix[0].size(); ++j)
            if (matrix[0][j] == 0)
                for (int i = 0; i < matrix.size(); ++i)
                    matrix[i][j] = 0;

        if (row0)
            for (int j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
        if (col0)
            for (int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
    }
};


```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)