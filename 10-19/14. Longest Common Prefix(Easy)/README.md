# 字符串数组最长公共前缀
#### *Longest Common Prefix*

* Write a function to find the longest common prefix string amongst an array of strings.

**example 1**
```
input: ['asdqowi','asdb', 'asdmnc']
output: 'asd'
```

### 思路
1. i从0开始自增，判断每个字符串 i 位置的字符是否一致，不一致则 i 之前的串为最长公共字符串。
2. 利用python zip函数的特点：
```
a = [1, 2, 3]
b = [4, 5, 6]
c = [7, 8, 9, 10]
zip(a, b, c) is =>
(1, 4, 7)

(2, 5, 8)

(3, 6, 9)
set((1, 1, 1)) = {'1'}
set((1, 1, 2)) = {'1', '2'}
```
`zip(*strs)`返回可迭代的zip对象，只要判断`set(item)`长度大于0，则表明此元素非公共字符。

下面给出两种算法的代码。



### 代码
```
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        prefix = ''
        i = 0
        while True:
            try:
                tmp = strs[0][i]
                for item in strs:
                    if item[i] != tmp:
                        return prefix
            except: #out of index range，表明遍历最短字符串完毕
                return prefix
            prefix += tmp
            i += 1
        return prefix


    def longestCommonPrefix_use_zip(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        prefix = ''
        for _, item in enumerate(zip(*strs)):
            if len(set(item)) > 1:
                return prefix
            else:
                prefix += item[0]
        return prefix
```