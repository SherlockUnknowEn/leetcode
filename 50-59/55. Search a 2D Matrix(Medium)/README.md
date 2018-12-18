# 搜索二维矩阵

#### *Search a 2D Matrix*

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。


英文题目:

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

**example 1**

```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

```

**example 2**

```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

```


---

### 思路

1. 容易想到的思路，将二维矩阵视为一个长列表，使用二分查找法，对于m*n的矩阵，时间复杂度为log(m*n)
2. 在上述基础之上可以进行优化：
    因为矩阵特点为: 每一行的第一个元素一定大于上一行的最后一个元素，因此可以对矩阵第一列先用二分查找法，找到target目标所在矩阵哪一行，再在此行中使用二分法查找目标在行中哪个位置。
    时间复杂度为 log(max(m, n))，仅取决于m n的较大值。



### 代码
```

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //binary search
        int m = matrix.size();
        if (m == 0 || matrix[0].size() == 0 || target < matrix[0][0] || target > matrix[m - 1][matrix[0].size() - 1])
            return false;
        int n = matrix[0].size();

        //优化版，两次二分查找
        int i = 0;
        int j = m;
        int start = 0;
        while (i < j)
        {
            int start = (i + j) / 2;
            if (matrix[start][0] == target)
                return true;
            if (matrix[start][0] > target)
                j = start - 1;
            if (matrix[start][0] < target)
                i = start + 1;
        }

        i = ((i - 1) >= 0 ? (i - 1) : 0) * n;
        j = ((j + 1) <= m ? (j + 1) : m) * n;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            if (matrix[mid / n][mid % n] > target)
                j = mid - 1;
            if (matrix[mid / n][mid % n] < target)
                i = mid + 1;
        }
        return false;
    }
};


```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)