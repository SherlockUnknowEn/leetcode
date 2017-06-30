# -*- coding: utf-8 -*-
# @Time    : 2017/6/30 上午10:39
# @Author  : fj
# @Site    : 
# @File    : Valid Parentheses.py
# @Software: PyCharm

# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#
# The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        brackets = {
            '(': ')',
            '[': ']',
            '{': '}'
        }
        stack = []
        for i in s:
            if i in brackets:
                stack.append(brackets[i])
            elif i in brackets.values():
                if len(stack) == 0 or stack.pop(-1) != i:
                    return False
        return len(stack) == 0

a = Solution().isValid('')
print(a)