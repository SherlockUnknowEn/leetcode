# -*- coding: utf-8 -*-
# @Time    : 2017/6/23 上午11:00
# @Author  : fj
# @Site    : 
# @File    : romanToInt.py
# @Software: PyCharm

# * Given a roman numeral, convert it to an integer.
#
# * Input is guaranteed to be within the range from 1 to 3999.

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        a = {'M': 1000, 'D': 500, 'C': 100, 'L': 50, 'X': 10, 'V': 5, 'I': 1}
        sum = 0
        for i in range(len(s) - 1): #range右边界len(s) - 1 保证 i + 1不会下标越界
            if a[s[i]] < a[s[i+1]]:
                sum -= a[s[i]]
            else:
                sum += a[s[i]]
        return sum + a[s[len(s) - 1]]

a = Solution().romanToInt('CCCLXXXIX')
print(a)