# -*- coding: utf-8 -*-
# @Time    : 2017/12/05 下午4:53
# @Author  : fj
# @Site    : 
# @File    : Substring with Concatenation of All Words.py
# @Software: PyCharm


# You are given a string, s, and a list of words, words, that are all of the same length.
# Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
# (order does not matter).

# For example, given:
# s: "barfoothefoobarman"
# words: ["foo", "bar"]
# output: [0, 9]
#
# s: "wordgoodgoodgoodbestword"
# words: ["word","good","best","good"]
# output: [8]
#
# s: "aaa"
# words: ["a", "b"]
# output: []


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
        for i in range(s_length - word_length * word_list_length + 1):
            seen = {}
            j = 0
            while j < word_list_length:
                w_tmp = s[i + j * word_length : i + (j+1) * word_length]
                if w_tmp in word_list:
                    seen[w_tmp] = seen.get(w_tmp, 0) + 1
                    if seen[w_tmp] > counts[w_tmp]:
                        break
                else:
                    break
                j += 1
            if j == word_list_length:
                ret.append(i)
        return ret


    # 此方法太复杂
    def findSubstring_old(self, s, word_list):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not word_list:
            return []
        m_idx = {} # key 是word，value是s.find找到的索引值
        m_key = {} #key是s.find找到的索引值，value是word

        m_count = {}  # key是word，value是word出现的次数

        #找到所有word在s的位置
        for item in word_list:
            m_idx[item] = set()
            m_count[item] = m_count.get(item, 0) + 1
            start = 0
            idx = 0
            while idx != -1:
                idx = s.find(item, start)
                if idx != -1:
                    m_idx[item].add(idx)
                    m_key[idx] = item
                    start = idx + 1

        #所有word的索引进行排序
        pailie = []
        for item in m_idx.values():
            # 如果某一个word的索引集合为空，直接返回None，表示未能找到此word的匹配项
            if len(item) == 0:
                return []
            for x in item:
                pailie.append(x)
        pailie.sort()

        word_length = len(word_list[0])
        word_list_length = len(word_list)

        #制造batch
        batch = []
        for item in pailie:
            hasBatch = True
            for i in range(1, word_list_length):
                if not item + i * word_length in pailie:
                    hasBatch = False
                    break
            if hasBatch:
                batch.append([item + x * word_length for x in range(word_list_length)])
        # 每个batch判断里面元素是否逐一来自words
        ret = []
        for b in batch:
            m_val = {} #key是word，value是待验证是否与m_count一致
            for item in b:
                m_val[m_key[item]] = m_val.get(m_key[item], 0) + 1
            #验证m_val是否与m_count一致
            found = True
            for key in m_count.keys():
                if m_count[key] != m_val[key]:
                    found = False
                    break
            if found:
                ret.append(b[0])
        return ret







a = Solution().findSubstring("wordgoodgoodgoodbestword", ["word","good","best","good"])
# a = Solution().findSubstring("aaa", ["a","b"])
print(a)

print(Solution().findSubstring("barfoothefoobarman",["foo", "bar"]))