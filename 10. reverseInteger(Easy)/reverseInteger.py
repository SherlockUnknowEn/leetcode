# Reverse digits of an integer.
#
# Example1: x = 123, return 321
# Example2: x = -123, return -321
#
# Note:
# The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # strx = ''
        # negative = x < 0
        # if negative:
        #     x = -x
        # while x / 10.0 != 0:
        #     strx += str(x % 10)
        #     x = int(x / 10)
        # if negative:
        #     strx = '-' + strx
        # try:
        #     ret = int(strx)
        #     if ret > 2147483647 or ret < -2147483648:
        #         return 0
        #     else:
        #         return ret
        # except Exception:
        #     return x
        sx = str(x)
        if sx[0] == '-':
            sx = '-' + sx[-1:0:-1]
        else:
            sx = sx[::-1]
        ret = int(sx)
        if ret > 2147483647 or ret < -2147483648:
            return 0
        else:
            return ret

a = Solution().reverse(123123123)
print(a)