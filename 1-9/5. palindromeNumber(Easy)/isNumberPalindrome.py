'''
Determine whether an integer is a palindrome. Do this without extra space.
'''

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        if len(str(x)) % 2 == 0:
            return int(str(x)[:len(str(x))//2]) == int(str(x)[len(str(x))//2:][::-1])
        else:
            return int(str(x)[:len(str(x))//2+1]) == int(str(x)[len(str(x))//2:][::-1])


a = Solution().isPalindrome(+2147447412)
print(a)
