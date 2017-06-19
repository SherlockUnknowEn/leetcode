# 寻找最长不重复子串
#### Longest Substring Without Repeating Characters

- Given a string, find the length of the **longest substring** without repeating characters.

- **Examples**:

- Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.

- Given `"bbbbb"`, the answer is `"b"`, with the length of 1.

- Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note that the answer must be a substring, `"pwke"` is a **subsequence** and not a **substring**.


### 思路(时间复杂度为O(n))
1. 遍历字符串，过程中将出现过的字符存入字典，key为字符，value为字符下标
2. 用maxLength保存遍历过程中找到的最大不重复子串的长度
3. 用start保存最长子串的开始下标
4. 如果字符已经出现在字典中，更新start的值
5. 如果字符不在字典中，更新maxLength的值
6. return maxLength

### 代码

``` python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
	    """
        :type s: str
        :rtype: int
        """
        start = maxLength = 0
        usedChar = {}

        for i in range(len(s)):
            if s[i] in usedChar and start <= usedChar[s[i]]:
                start = usedChar[s[i]] + 1
            else:
                maxLength = max(maxLength, i - start + 1)
            usedChar[s[i]] = i

        return maxLength
```

