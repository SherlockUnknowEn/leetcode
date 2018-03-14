# -*- coding: utf-8 -*-
# @Time    : 2018/03/14 上午11:36
# @Author  : fj
# @Site    : 
# @File    : Longest Valid Parentheses.py
# @Software: PyCharm

# Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
#
# For "(()", the longest valid parentheses substring is "()", which has length = 2.
#
# Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

class Solution(object):

    def longestValidParentheses(self, s):
        '''
        :param s:
        :return:
        '''
        left = right = maxcount = 0
        for item in s:
            if item == '(':
                left += 1
            elif item == ')':
                right += 1
            if left < right:
                left = right = 0
            if left == right:
                maxcount = max(maxcount, 2 * right)

        left = right = 0
        for item in reversed(s):
            if item == '(':
                left += 1
            elif item == ')':
                right += 1
            if left > right:
                left = right = 0
            if left == right:
                maxcount = max(maxcount, 2 * right)

        return maxcount


a = Solution().longestValidParentheses(")()())")
b = Solution().longestValidParentheses("()(()")
c = Solution().longestValidParentheses('()')
print(a)
print(b)
print(c)