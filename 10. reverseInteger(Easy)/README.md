# 反转整数
#### *Reverse Integer*

**example 1**
```
input: x = 123, return 321
```
**example 2**
```
input: x = -123, return -321
```
note: 
* The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
### 思路
1. 简单到不用说思路，只需要注意在python里int的存储整数是没有最大值上限的，于是为了AC，我们只好画蛇添足般加了if判断
2. 32位整数存储范围是`-2147483648`到`2147483647`


### 代码
```
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sx = str(x)
        if sx[0] == '-':
            sx = '-' + sx[-1:0:-1]
        else:
            sx = sx[::-1]
        ret = int(sx)
        if ret > 2147483647 or ret < -2147483648:
            return 0
        else:
            return ret
```