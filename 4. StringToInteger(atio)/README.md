# 实现atoi函数(string转integer)
#### *String to Integer (atoi)*

* Implement atoi to convert a string to an integer.
* Hint: Carefully consider all possible input cases. 
* Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front..

* **Example 1:**

```
Input: ""
Output: 0
``` 


* **Example 2:**

```
Input: "+2"
Output: 2
``` 

* **Example 3:**

```
Input: "+-2"
Output: 0
``` 

* **Example 4:**

```
Input: "+"
Output: 0
``` 

* **Example 5:**

```
Input: "-223pasudasd"
Output: -223
``` 

### 思路
1. 利用Python内置的int(str)函数可以将字符串快速转换成int型
2. 利用int(str)是否抛出异常来快速判断str能否被转换成int，进而迅速确定输入字符串中第一个非数字字符的位置
3. 需要注意处理`+`,`-`符号的问题

### 代码
```
class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        retstr = ''
        try:
            for _, item in enumerate(s):
                if item == '+' or item == '-':
                    retstr += item
                else:
                    retstr += str(int(item))
        finally:
            if len(retstr) == 0:
                return 0
            else:
                try:
	                # 如果 retstr 是 '-' 或者 '+',len(retstr) != 0 但是会抛出异常，此时返回0
	                # 由于python的int没有取值上限，如果规定int为32位，需要判断int(retstr)是否大于2147483647或者小余-2147483648
                    return int(retstr)
                except:
                    return 0
```