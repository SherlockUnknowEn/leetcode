# 单词搜索

#### *Word Search*

给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用


英文题目:

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

**example 1**

```
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

```

---

### 思路

1. 回溯法，使用cannot矩阵(初始全0)记录已经走过的路径(置1)，每次都尝试向上下左右四个方向走一步，同时更新cannot矩阵，
2. 若其中一个方向能走通(每一步都与单词的对应字符相等)则返回true，若4个方向都走不通，cannot对应位置修改回0.
    

### 代码
```

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() <= 0)
			return false;
		vector<vector<char>> cannot(board.size(), vector<char>(board[0].size()));
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (go2(board, i, j, cannot, word, 0))
					return true;
			}
		}
		return false;
	}
private:
	bool go2(const vector<vector<char>>& board, int i, int j, vector<vector<char>>& cannot, const string& word, int index)
	{
		if (index >= word.length())
			return true;
		if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || cannot[i][j] == 1)
			return false;
		if (board[i][j] != word[index])
			return false;
		cannot[i][j] = 1; //此路走过
		if (go2(board, i - 1, j, cannot, word, index + 1) //up
			|| go2(board, i + 1, j, cannot, word, index + 1) //donw
			|| go2(board, i, j - 1, cannot, word, index + 1) //left
			|| go2(board, i, j + 1, cannot, word, index + 1)) //right
			return true;
		cannot[i][j] = 0; //回溯
		return false;

	}
};

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)