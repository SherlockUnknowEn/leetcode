# 验证数独题目是否合规

#### *Valid Sudoku*

* 验证数独题目是否合规。
* 数独题目存储在二维字符数组board中
* 空方块存储为`.`
* 只验证重复项，不需要验证数独是否有解
* [数独参考资料](http://sudoku.com.au/TheRules.aspx)

题目原文:

* Determine if a Sudoku is valid, according to: [Sudoku Puzzles - The Rules](http://sudoku.com.au/TheRules.aspx).
* The Sudoku board could be partially filled, where empty cells are filled with the character `.`
* A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.


**example 1**

```
Input: 
[[".","8","7","6","5","4","3","2","1"],
 ["2",".",".",".",".",".",".",".","."],
 ["3",".",".",".",".",".",".",".","."],
 ["4",".",".",".",".",".",".",".","."],
 ["5",".",".",".",".",".",".",".","."],
 ["6",".",".",".",".",".",".",".","."],
 ["7",".",".",".",".",".",".",".","."],
 ["8",".",".",".",".",".",".",".","."],
 ["9",".",".",".",".",".",".",".","."]]
 
Output: True
```

**example 2**

```
Input: 
[[".",".","5",".",".",".",".",".","6"],
 [".",".",".",".","1","4",".",".","."],
 [".",".",".",".",".",".",".",".","."],
 [".",".",".",".",".","9","2",".","."],
 ["5",".",".",".",".","2",".",".","."],
 [".",".",".",".",".",".",".","3","."],
 [".",".",".","5","4",".",".",".","."],
 ["3",".",".",".",".",".","4","2","."],
 [".",".",".","2","7",".","6",".","."]]
 
Output: True
```


---

### 思路

1. 需要验证三种情况
2. 每一行不能有重复数字
3. 每一列不能有重复数字
4. 每一个九宫格不能有重复数字



### 代码
```
class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        return self.__checkRow(board) and self.__checkColunm(board) and self.__checkJiuGong(board)


    def __checkColunm(self, board):
        for i in range(len(board)):
            s = set()
            for j in range(len(board[i])):
                if board[j][i] != '.' and board[j][i] in s:
                    return False
                else:
                    s.add(board[j][i])
        return True

    def __checkRow(self, board):
        for i in range(len(board)):
            s = set()
            for j in range(len(board[i])):
                if board[i][j] != '.' and board[i][j] in s:
                    return False
                else:
                    s.add(board[i][j])
        return True

    def __checkJiuGong(self, board):
        for i in range(0, len(board), 3):
            for j in range(0, len(board), 3):
                s = set()
                for iplus in range(3):
                    for jplus in range(3):
                        if board[i + iplus][j + jplus] != '.' and board[i + iplus][j + jplus] in s:
                            return False
                        else:
                            s.add(board[i + iplus][j + jplus])

        return True
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)