'''
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example:
Input: "cbbd"
Output: "bb"
'''

class Solution(object):

    def longestPalindrome(self, s):
        self.maxlen = 0
        self.retstr = ''
        if len(s) < 2:
            return s
        for i in range(len(s)):
            self.__find_palindrome(s, i, i) #奇回文
            self.__find_palindrome(s, i, i+1) #偶回文
        return self.retstr


    def __find_palindrome(self, s, j, k):
        while j >= 0 and k < len(s) and s[j] == s[k]:
            j -= 1
            k += 1
        if self.maxlen < k - j + 1:
            self.maxlen = k - j + 1
            self.retstr = s[j+1:k]


    def longestPalindrome_old(self, s):
        retlist = []
        for i, item in enumerate(s):
            if i + 1 < len(s) and s[i] == s[i + 1]:
                count = 1
                while (i - count) >= 0 and (i + 1 + count) < len(s):
                    if s[i - count] == s[i + 1 + count]:
                        count += 1
                        if i + 1 + count == len(s) or i - count < 0:
                            retlist.append(s[i - count + 1:i + 1 + count])
                    else:
                        retlist.append(s[i - count + 1:i + 1 + count])
                        break
                retlist.append(s[i:i + 2])
            if i + 2 < len(s) and s[i] == s[i + 2]:
                count = 1
                while (i - count) >= 0 and (i + 2 + count) < len(s):
                    if s[i - count] == s[i + 2 + count]:
                        count += 1
                        if i + 2 + count == len(s) or i - count < 0:
                            retlist.append(s[i - count + 1:i + 2 + count])
                    else:
                        retlist.append(s[i - count + 1:i + 2 + count])
                        break
                retlist.append(s[i:i + 3])
        if len(retlist) == 0:
            return s[0]
        maxlen = len(retlist[0])
        retstr = retlist[0]
        for _, item in enumerate(retlist):
            if len(item) > maxlen:
                maxlen = len(item)
                retstr = item
        return retstr





a = Solution().longestPalindrome4('1234554321p')
print(a)