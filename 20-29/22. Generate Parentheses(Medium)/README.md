# 构造n个成对括号
#### *Generate Parentheses*

* 给出一个整数n，实现一个函数生成n对小括号，n对小括号的左右括弧顺序不限，但应该闭合。
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



**example 1**
```
For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
].
```

---

### 思路

1. `n=2`的情况为`n=1`时的括号串`()`中在缝隙位置再插入一个括号，如`1(2)3`中`1,2,3`位置。可以用`set`剔除重复元素。
2. 递归解决，`n=3`时为在`()()`和`(())`中再插入一个括号。
3. 思路2来源自[leetcode讨论区](https://discuss.leetcode.com/topic/9048/7-lines-in-python-44-ms)，使用open记录已经有多少左括号，如果n==0，将`")" * open`闭合。


 
### 代码
```
class Solution(object):

    def __init__(self):
        self.table = {1: ['()']}

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 1:
            return self.table[1]
        if n-1 in self.table.keys():
            nset = set()
            n1set = self.table[n-1]
            for _, item in enumerate(n1set):
                for j in range(len(item)):
                    nset.add(item[0:j] + '()' + item[j:])
            self.table[n] = list(nset)
            return self.table[n]
        else:
            self.generateParenthesis(n-1)
            return self.generateParenthesis(n)


    def gen2(self, n, open=0):
        if n == 0: return [')'*open]
        if open == 0:
            return ['('+x for x in self.gen2(n-1, 1)]
        else:
            return [')'+x for x in self.gen2(n, open-1)] + ['('+x for x in self.gen2(n-1, open+1)]
```
