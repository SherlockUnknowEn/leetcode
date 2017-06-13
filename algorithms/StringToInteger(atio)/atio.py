'''
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
'''


class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        retstr = ''
        try:
            for _, item in enumerate(s):
                if item == '+' or item == '-':
                    retstr += item
                else:
                    retstr += str(int(item))
        finally:
            if len(retstr) == 0:
                return 0
            else:
                try:
                    # 如果 retstr 是 '-' 或者 '+',len(retstr) != 0 但是会抛出异常，此时返回0
	                # 由于python的int没有取值上限，如果规定int为32位，需要判断int(retstr)是否大于2147483647或者小余-2147483648
                    return int(retstr)
                except:
                    return 0

s = Solution().myAtoi('-2')
print(s)