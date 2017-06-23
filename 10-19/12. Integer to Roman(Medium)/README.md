# 阿拉伯数字转换成罗马数字
#### *Integer to Roman*

* Given an integer, convert it to a roman numeral.

* Input is guaranteed to be within the range from 1 to 3999.

**example 1**
```
input: CCCLXXXIX
output: 389
```

### 思路
1. 用表记录关键的罗马数字和阿拉伯数字，将输入循环除以1000，900，500 ... 这些关键数字，余数为`y`，将对应的罗马字符串加`y`次
2. 看到大神的思路，也是查表，但更加精妙，将数字分解为千位，百位，十位和个位，然后查表将字符串相加，很神奇的思路，刚看到的时候惊叹了一下，代码如下


### 代码
```
class Solution(object):
    # 思路1
    def intToRoman1(self, num):
        """
        :type num: int
        :rtype: str
        """
        arabic = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        roman = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        ret = ''
        i = 0
        while num:
            yu = num // arabic[i]
            ret += roman[i] * yu
            num = num - yu * arabic[i]
            i += 1
        return ret

	# 神奇的思路2
    def intToRoman2(self, num):
        M = ['', 'M', 'MM', 'MMM'] #0, 1000, 2000, 3000
        C = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'] #0, 100, 200, ... , 900
        X = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'] #0, 10, 20, ... , 90
        I = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX'] #0, 1, 2, ... , 9
        return M[num // 1000] + C[(num % 1000) // 100] + X[(num % 100) // 10] + I[num % 10]
```