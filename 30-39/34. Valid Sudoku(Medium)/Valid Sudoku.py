# -*- coding: utf-8 -*-
# @Time    : 2017/3/15 上午10:39
# @Author  : fj
# @Site    :
# @File    : Valid Sudoku.py
# @Software: PyCharm

# Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
#
# The Sudoku board could be partially filled, where empty cells are filled with the character '.'
#
# Note:
# A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

# Example 1: True
# [[".","8","7","6","5","4","3","2","1"],
#  ["2",".",".",".",".",".",".",".","."],
#  ["3",".",".",".",".",".",".",".","."],
#  ["4",".",".",".",".",".",".",".","."],
#  ["5",".",".",".",".",".",".",".","."],
#  ["6",".",".",".",".",".",".",".","."],
#  ["7",".",".",".",".",".",".",".","."],
#  ["8",".",".",".",".",".",".",".","."],
#  ["9",".",".",".",".",".",".",".","."]]

# Example 2: True
# [[".",".","5",".",".",".",".",".","6"],
#  [".",".",".",".","1","4",".",".","."],
#  [".",".",".",".",".",".",".",".","."],
#  [".",".",".",".",".","9","2",".","."],
#  ["5",".",".",".",".","2",".",".","."],
#  [".",".",".",".",".",".",".","3","."],
#  [".",".",".","5","4",".",".",".","."],
#  ["3",".",".",".",".",".","4","2","."],
#  [".",".",".","2","7",".","6",".","."]]


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


a = Solution().isValidSudoku([[".",".","5",".",".",".",".",".","6"],[".",".",".",".","1","4",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".","9","2",".","."],["5",".",".",".",".","2",".",".","."],[".",".",".",".",".",".",".","3","."],[".",".",".","5","4",".",".",".","."],["3",".",".",".",".",".","4","2","."],[".",".",".","2","7",".","6",".","."]])
print(a)