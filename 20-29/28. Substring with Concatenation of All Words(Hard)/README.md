# 寻找所有词串联的子串的位置

#### *Substring with Concatenation of All Words*

* 给定一个字符串s和一个字符串数组word_list，字符串数组中所有元素的长度都是一致的。
* 找到字符串数组word_list所有元素串联起来的新字符串（顺序不限制）w，在s中的所有子串开始的位置

题目原文:

* ```
  You are given a string, s, and a list of words, words, that are all of the same length. 
  Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
  ```



**example 1**

```
input: s: "barfoothefoobarman", word_list: ["foo", "bar"]
output: [0, 9]
```

**example 2**

```
input: s: "wordgoodgoodgoodbestword", word_list: ["word","good","best","good"]
output: [8]
```

**example 3**

```
input: s: "aaa", word_list: ["a", "b"]
output: []
```

---

### 思路

1. 由于`word_list`中的元素可能有相同字符串，因此使用map记录，key为`word_list中`的元素，value为在`word_list`中的出现次数，此map记为`counts`
2. 记`word_list`每个元素的串长为`word_length`，记数组`word_list`的长度为`word_list_length`
3. 遍历s，步长为1，每次取`word_length`长度的子串`w_tmp`，检查`word_list`是否在`word_list`中，如果在，则继续往后取，一共取`word_list_length`次，同时用map记录`word_list`出现的次数，此map记为`seen`。如果`seen`和`counts`键值都一致，则代表已找到符合要求的下标。



### 代码
```
class Solution(object):
    def findSubstring(self, s, word_list):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        counts = {}
        ret = []
        for item in word_list:
            counts[item] = counts.get(item, 0) + 1
        s_length, word_length, word_list_length = len(s), len(word_list[0]), len(word_list)
        #遍历s
        for i in range(s_length - word_length * word_list_length + 1):
            seen = {}
            j = 0
            while j < word_list_length:
                w_tmp = s[i + j * word_length : i + (j+1) * word_length]
                # 如果w_tmp在counts中
                if w_tmp in word_list:
                    # 如果w_tmp出现次数超过在word_list中的出现次数，不符合
                    seen[w_tmp] = seen.get(w_tmp, 0) + 1
                    if seen[w_tmp] > counts[w_tmp]:
                        break
                else:
                    break
                j += 1
            if j == word_list_length:
                ret.append(i)
        return ret
```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)