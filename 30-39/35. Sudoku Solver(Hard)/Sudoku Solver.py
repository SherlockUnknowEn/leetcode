# -*- coding: utf-8 -*-
# @Time    : 2017/4/13 上午11:31
# @Author  : fj
# @Site    :
# @File    : Sudoku Solver.py
# @Software: PyCharm

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