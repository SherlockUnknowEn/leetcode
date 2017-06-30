# 验证大小中括号是否成对闭合匹配
#### *Valid Parentheses*

* 验证大小中括号是否成对闭合匹配。
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not..

**example 1**
```
input: '{{()}}'
output: True
```

**example 2**
```
input: '(([)])'
output: False
```

**example 3**
```
input: ''
output: True
```

### 思路

1. 使用栈（先进后出）
2. 如果遇到左边符号`{`，`[`，`(`，则将其对应的右边符号`}`，`]`，`)`入栈，如果遇到右边符号，则判断栈顶元素是否匹配，不匹配则返回False
3. 最后栈空，则完全闭合匹配，返回True

 
### 代码
```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        brackets = {
            '(': ')',
            '[': ']',
            '{': '}'
        }
        stack = []
        for i in s:
            if i in brackets:
                stack.append(brackets[i])
            elif i in brackets.values():
                if len(stack) == 0 or stack.pop(-1) != i:
                    return False
        return len(stack) == 0
```