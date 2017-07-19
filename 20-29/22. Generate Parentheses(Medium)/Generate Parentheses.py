# -*- coding: utf-8 -*-
# @Time    : 2017/7/3 下午3:01
# @Author  : fj
# @Site    : 
# @File    : Generate Parentheses.py
# @Software: PyCharm

# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
#
# For example, given n = 3, a solution set is:
#
# [
#   "((()))",
#   "(()())",
#   "(())()",
#   "()(())",
#   "()()()"
# ]

class Solution(object):

    def __init__(self):
        self.table = {1: ['()']}

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 1:
            return self.table[1]
        if n-1 in self.table.keys():
            nset = set()
            n1set = self.table[n-1]
            for _, item in enumerate(n1set):
                for j in range(len(item)):
                    nset.add(item[0:j] + '()' + item[j:])
            self.table[n] = list(nset)
            return self.table[n]
        else:
            self.generateParenthesis(n-1)
            return self.generateParenthesis(n)


    def gen2(self, n, open=0):
        if n == 0: return [')'*open]
        if open == 0:
            return ['('+x for x in self.gen2(n-1, 1)]
        else:
            return [')'+x for x in self.gen2(n, open-1)] + ['('+x for x in self.gen2(n-1, open+1)]



a = Solution().gen2(2)
print(a)