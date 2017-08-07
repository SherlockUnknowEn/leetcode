# 两数相除——不允许使用高级运算
#### *Divide Two Integers*

* 实现两整数相除，不允许使用乘法、除法、和取余运算。
* 如果结果溢出（int范围为-2147483648 ~ 2147483647），返回MAX_INT

题目原文:

* Divide two integers without using multiplication, division and mod operator.
* If it is overflow, return MAX_INT..




**example **
```
input: 1001, 2
output: 500
```

---

### 思路

1. 利用减法，将被除数减去除数，减去的次数累计即为最后结果
2. 为了解决效率问题，可以减去除数的倍数，利用位运算，每次除数左移一位（2倍），次数相应加对应的倍数。
3. 如果左移一位的除数过大，除数还原。
4. 注意处理除法运算中正负号的问题。


 
### 代码
```
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        pos = (dividend < 0) is (divisor < 0)
        dividend, divisor = abs(dividend), abs(divisor)
        result = 0
        while dividend >= divisor:
            tmp, i = divisor, 1
            while dividend - tmp >= 0:
                dividend -= tmp
                result += i
                i <<= 1
                tmp <<= 1
        if not pos:
            result = -result
        return min(2147483647, max(result, -2147483648))
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)