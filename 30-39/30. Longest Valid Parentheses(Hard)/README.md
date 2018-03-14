# 求最长的括弧匹配子串的长度

#### *Longest Valid Parentheses*

* 给定一个字符串，仅仅包含`(`和`)`两种字符，找出符合括号封闭规则的最长子串的长度。
* 如`(())(((`，符合封闭规则的是`(())`，则最长子串为4。

题目原文:

* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


**example 1**

```
s: (()
return: 2
```

**example 2**

```
s: )()())
return: 4
```


---

### 思路

1. `left = right = maxcount = 0`
2. 左到右遍历字符串，遇到`(`则`left`加一，遇到`)`则`right`加一
3. 若`left == right`，则发现闭合子串，计算长度与`maxcount`进行比较大小并将较大值赋值给`maxcount`
4. 若`left < right`，则左括号的个数小于右括号的个数， `left`与`right`归零从新计数
4. 若遍历完毕时`left > right`，则需要处理右边界问题，即`(`比`)`个数多，且最长子串在字符串最右边，如`()(((((()))`，最长子串应为最右边的`((()))`
5. 解决右边界问题，从右到左遍历再遍历一次，与上述步骤相同，最后返回maxcount即为结果



### 代码
```
class Solution(object):

    def longestValidParentheses(self, s):
        '''
        :param s:
        :return:
        '''
        left = right = maxcount = 0
        for item in s:
            if item == '(':
                left += 1
            elif item == ')':
                right += 1
            if left < right:
                left = right = 0
            if left == right:
                maxcount = max(maxcount, 2 * right)

        left = right = 0
        for item in reversed(s):
            if item == '(':
                left += 1
            elif item == ')':
                right += 1
            if left > right:
                left = right = 0
            if left == right:
                maxcount = max(maxcount, 2 * right)

        return maxcount
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)