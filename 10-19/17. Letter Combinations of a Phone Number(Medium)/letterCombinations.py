# -*- coding: utf-8 -*-
# @Time    : 2017/6/28 上午9:41
# @Author  : fj
# @Site    : 
# @File    : letterCombinations.py
# @Software: PyCharm


# Given a digit string, return all possible letter combinations that the number could represent.
# A mapping of digit to letters (just like on the telephone buttons) is given below.

# Input:Digit string "23"
# Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

# Note:
# Although the above answer is in lexicographical order, your answer could be in any order you want.

# reduce把一个函数作用在一个序列[x1, x2, x3, ...]上，这个函数必须接收两个参数，reduce把结果继续和序列的下一个元素做累积计算，其效果就是：

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        from functools import reduce
        if not digits:
            return []
        nums = '0 1 abc def ghi jkl mno pqrs tuv wxyz'.split(' ')
        return reduce(lambda last, d: [x + y for x in last for y in nums[int(d)]], digits, [''])  # 第三个参数是initial



    def letterCombinations_old(self, digits):
        if not digits:
            return []
        nums = '0 1 abc def ghi jkl mno pqrs tuv wxyz'.split(' ')
        ret = [_ for _ in nums[int(digits[0])]]
        digits = digits[1:]
        while digits:
            ret = [x + y for x in ret for y in nums[int(digits[0])]]
            digits = digits[1:]
        return ret


a = Solution().letterCombinations('232')
print(a)
print([_ for _ in [1,2,3]])
