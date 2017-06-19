# 不使用任何额外变量判断回文数字
#### *Palindrome Number*

* Determine whether an integer is a palindrome. Do this without extra space.
* Notes: any negative number is not palindrome.

* **Example 1:**

```
Input: 1221
Output: True
``` 

* **Example 2:**

```
Input: -1221
Output: False
``` 

### 思路
1. 不能使用额外的变量，只能用参数x完成，由于不能使用额外变量的限制，所以代码可读性有点差
2. 将int转成str，利用len(str)求出整数的位数，然后用str字符串的切片来取得前后对称部分，如input为`x = 1234`则`len(str(x))`为4，`3`的下标为`len(str(x))//2`
3. 利用python切片可以快速reverse字符串, `a = [1,2,3]`则`a[::-1]`为`[3,2,1]`
4.  `x = 1234`可以通过判断`12`是否等于`43`来得出是否是回文，根据上一点`12`可以用切片`str(x)[ : len(str(x))//2]`求得，`43`可以根据第4点用`str(x)[len(str(x))//2 : ]`求得
5. 仍然可以分为奇回文和偶回文处理，参考阅读[寻找字符串中最长回文](http://blog.csdn.net/github_37953781/article/details/72858519)，`12321`以3为对称中心，`123321`以33为对称中心

### 代码
```
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        if len(str(x)) % 2 == 0:
            return int(str(x)[ : len(str(x))//2]) == int(str(x)[len(str(x))//2 : ][ : :-1])
        else:
            return int(str(x)[ : len(str(x))//2+1]) == int(str(x)[len(str(x))//2 : ][ : :-1])
```