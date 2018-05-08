# 字符串相乘

#### *Multiply Strings*

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

**说明:**

1. `num1` 和 `num2` 的长度小于110。
2. `num1` 和 `num2` 只包含数字 0-9。
3. `num1` 和 `num2` 均不以零开头，除非是数字 0 本身。
4. **不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。**


英文题目:

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

**note:**

1. The length of both `num1` and `num2` is < 110.
2. Both `num1` and `num2` contain only digits 0-9.
3. Both `num1` and `num2` do not contain any leading zero, except the number 0 itself.
4. You **must not use any built-in BigInteger library or convert the inputs to integer** directly.



**example 1**

```
Input: num1 = "2", num2 = "3"
Output: "6"
```

**example 2**

```
Input: num1 = "123", num2 = "456"
Output: "56088"
```



---

### 思路

1. 利用字符`1`与整数1的ASCII码相差48
2. example: `751` = (ascii('7') - 48) * 10² + (ascii('5') - 48) * 10 + ascii('1') - 48


### 代码
```
class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1_int = 0
        num2_int = 0
        for i in range(len(num1)):
            num1_int += (ord(num1[i]) - 48) * 10**(len(num1) -i -1)
        for i in range(len(num2)):
            num2_int += (ord(num2[i]) - 48) * 10**(len(num2) -i -1)
        result_int = num1_int * num2_int
        result_str = ''
        while result_int > 0:
            ascode = result_int % 10
            result_str = chr(ascode + 48) + result_str
            result_int = result_int // 10
        return result_str if result_str else '0'
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)