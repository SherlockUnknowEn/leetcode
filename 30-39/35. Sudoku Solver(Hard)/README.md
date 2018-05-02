# 数独解题器

#### *Sudoku Solver*

* 解出给定数独题目。
* 数独题目存储在二维字符数组board中
* 空方块存储为`.`
* 假设有且仅有唯一解
* [数独参考资料](http://sudoku.com.au/TheRules.aspx)

题目原文:

* Write a program to solve a Sudoku puzzle by filling the empty cells.
* A sudoku solution must satisfy all of the following rules:
	* each of the digits `1-9` must occur exactly once in each row.
	* Each of the digits `1-9` must occur exactly once in each column.
	* Each of the the digits `1-9` must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
* Empty cells are indicated by the character `.`

Note:

* The given board contain only digits 1-9 and the character '.'.
* You may assume that the given Sudoku puzzle will have a single unique solution.
* The given board size is always 9x9.


**example 1**

```
Input: 
[[".",".","9","7","4","8",".",".","."],
["7",".",".",".",".",".",".",".","."],
[".","2",".","1",".","9",".",".","."],
[".",".","7",".",".",".","2","4","."],
[".","6","4",".","1",".","5","9","."],
[".","9","8",".",".",".","3",".","."],
[".",".",".","8",".","3",".","2","."],
[".",".",".",".",".",".",".",".","6"],
[".",".",".","2","7","5","9",".","."]]
 
Output: 
[['5' '1' '9' '7' '4' '8' '6' '3' '2']
 ['7' '8' '3' '6' '5' '2' '4' '1' '9']
 ['4' '2' '6' '1' '3' '9' '8' '7' '5']
 ['3' '5' '7' '9' '8' '6' '2' '4' '1']
 ['2' '6' '4' '3' '1' '7' '5' '9' '8']
 ['1' '9' '8' '5' '2' '4' '3' '6' '7']
 ['9' '7' '5' '8' '6' '3' '1' '2' '4']
 ['8' '3' '2' '4' '9' '1' '7' '5' '6']
 ['6' '4' '1' '2' '7' '5' '9' '8' '3']]
```


---

### 思路

1. 思路来自于leetcode最高赞答案。
2. 使用回溯法，遍历所有格子，每次遇到空白格子，尝试填入1-9所有数字，验证填入的数字是否符合规则（每行，每列，小九宫格内唯一）
3. 每填入一个数字，递归上述过程
4. 若遍历完所有格子并都填入了数字，则解题结束，返回true
5. 若有某一个格子1-9都不能填入，则返回false
6. 返回false后会回到上一个递归调用处，利用此特性进行回溯（详情见代码）



### 代码
```
import numpy as np

class Solution:

    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board or len(board) == 0:
            return
        self.solve(board)


    def solve(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for x in '123456789':
                        if self.validate(board, i, j, x):
                            board[i][j] = x
                            if self.solve(board):
                                return True
                            else:
                                # false即填入x后递归调用到某一深度后，无法得到解，回溯 
                                board[i][j] = '.'
                    #如果尝试1-9都不能填入，则返回false，回到上一个递归调用口
                    return False
        return True



    def validate(self, board, row, column, x):
        for i in range(9):
            if board[row][i] == x:
                return False
            if board[i][column] == x:
                return False
        h = (row // 3) * 3
        w = (column // 3) * 3
        for i in range(3):
            for j in range(3):
                if board[h + i][w + j] == x:
                    return False
        return True



board = [[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]]
Solution().solveSudoku(board)
print(np.array(board))
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)