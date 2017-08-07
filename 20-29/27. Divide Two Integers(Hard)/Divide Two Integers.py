# -*- coding: utf-8 -*-
# @Time    : 2017/8/1 下午5:23
# @Author  : fj
# @Site    : 
# @File    : Divide Two Integers.py
# @Software: PyCharm

# Divide two integers without using multiplication, division and mod operator.
#
# If it is overflow, return MAX_INT.

class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        pos = (dividend < 0) is (divisor < 0)
        dividend, divisor = abs(dividend), abs(divisor)
        result = 0
        while dividend >= divisor:
            tmp, i = divisor, 1
            while dividend - tmp >= 0:
                dividend -= tmp
                result += i
                i <<= 1
                tmp <<= 1
        if not pos:
            result = -result
        return min(2147483647, max(result, -2147483648))

a = Solution().divide(1, 2)
print(a)
