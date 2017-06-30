# -*- coding: utf-8 -*-
# @Time    : 2017/6/30 上午10:24
# @Author  : fj
# @Site    : 
# @File    : removeNthFromEnd.py
# @Software: PyCharm


# * 给定一个链表，移除倒数第n个元素，返回链表头部。
# * Given a linked list, remove the nth node from the end of list and return its head.
#
# Note:
# Given n will always be valid.
# Try to do this in one pass.
#
#
# **example 1**
#
# ```
# Given linked list: 1->2->3->4->5, and n = 2.
#
# After removing the second node from the end, the linked list becomes 1->2->3->5.
# ```
#
# **example 2**
# ```
# Given linked list: 1, and n = 1.
# output: None
# ```
#
# **example 3**
# ```
# Given linked list: 1->2->3, and n = 3.
# output: 2->3
# ```



# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        a = b = head
        for i in range(n):
            b = b.next
        if not b:
            return head.next
        while b.next:
            a = a.next
            b = b.next
        a.next = a.next.next
        return head


h = ListNode(1)
# h.next = ListNode(2)
# h.next.next = ListNode(3)
# h.next.next.next = ListNode(4)
# h.next.next.next.next = ListNode(5)

a = Solution().removeNthFromEnd(h, 1)
print(a)
