# -*- coding: utf-8 -*-
# @Time    : 2017/6/19 下午4:06
# @Author  : fj
# @Site    : 
# @File    : addTwoNumbers.py
# @Software: PyCharm


# You are given two non-empty linked lists representing two non-negative integers.
# The digits are stored in reverse order and each of their nodes contain a single digit.
# Add the two numbers and return it as a linked list.
#
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        s1 = self.genS(l1)
        s2 = self.genS(l2)
        re = str(int(s1) + int(s2))[::-1]
        tmp = result = ListNode(int(re[0]))
        for i in range(1, len(re)):
            tmp.next = ListNode(int(re[i]))
            tmp = tmp.next
        return result

    def genS(self, li):
        s = ''
        while li:
            s += str(li.val)
            li = li.next
        return s[::-1]

a = ListNode(2)
a.next = ListNode(6)
b = ListNode(3)
b.next = ListNode(7)
re =  Solution().addTwoNumbers(a, b)
print(re.next.val)