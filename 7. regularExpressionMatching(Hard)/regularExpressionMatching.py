'''

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
isMatch('bbbba', '.*a*a') → true
isMatch('a', '.*..a*') → False
isMatch('a', 'ab*') → true 
isMatch('ab', '.*c') → False 
'''

# AC 的方案
class Solution(object):
    def matchChar(self, sc, pc):
        return sc == pc or pc == '.'

    def isEndOfStar(self, p):
        while p != '':
            if len(p) == 1 or len(p) > 1 and p[1] != '*':
                return False
            p = p[2:]
        return True

    def isMatch(self, s, p):
        if p == '':
            return s == ''

        if s == '':
            return self.isEndOfStar(p)

        if (len(p) > 1 and p[1] != '*') or len(p) == 1:
            # without *
            if not self.matchChar(s[0], p[0]):
                return False
            else:
                return self.isMatch(s[1:], p[1:])

        else:
            # with *
            # try see x* is empty
            if self.isMatch(s[0:], p[2:]):
                return True

            # x* 可以 代表 x 一到多次
            while self.matchChar(s[0], p[0]):
                s = s[1:]

                if self.isMatch(s, p[2:]):
                    return True

                if s == '':
                    return self.isEndOfStar(p)
            return False