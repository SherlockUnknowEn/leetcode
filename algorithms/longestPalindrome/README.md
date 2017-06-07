# 查找字符串最长回文
#### *Longest Palindromic Substring*

* Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

* **Example:**

```
Input: "babad"
Output: "bab"
``` 

* Note: "aba" is also a valid answer.

* **Example:**

```
Input: "cbbd"
Output: "bb"
``` 
### 思路
1. 回文有奇回文和偶回文，`abcba`是奇回文，`abccba`是偶回文
2. 回文都是中心对称，找到对称点后，同时向前后寻找回文的最长串即可
3. 奇回文和偶回文可以归为同一种情况，即`abcba`以`c`为对称点，`abccba`以`cc`为对称点，但为了代码可读性，可以分开讨论

### 代码
```
class Solution(object):

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
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
```