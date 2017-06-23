# -*- coding: utf-8 -*-
# @Time    : 2017/6/23 下午1:38
# @Author  : fj
# @Site    : 
# @File    : longestCommonPrefix.py
# @Software: PyCharm

# Write a function to find the longest common prefix string amongst an array of strings.

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
            except:
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

a = Solution().longestCommonPrefix_use_zip(['asdqowi','asdb', 'asdmnc'])
print(a)

