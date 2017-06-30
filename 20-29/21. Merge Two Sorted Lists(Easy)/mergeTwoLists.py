# -*- coding: utf-8 -*-
# @Time    : 2017/6/30 下午1:03
# @Author  : fj
# @Site    : 
# @File    : mergeTwoLists.py
# @Software: PyCharm

# Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if None in (l1, l2):
            return l1 or l2
        head = tail = l1 if l1.val <= l2.val else l2
        a = l1 if l1.val > l2.val else l1.next
        b = l2 if l1.val <= l2.val else l2.next
        while a and b:
            if a.val <= b.val:
                tail.next = a
                tail, a = tail.next, a.next
            else:
                tail.next = b
                tail, b = tail.next, b.next
        tail.next = a or b
        return head

l1 = ListNode(2)
# l1.next = ListNode(2)
# l1.next.next = ListNode(5)

l2 = ListNode(1)
a = Solution().mergeTwoLists(l1, l2)
print(a.val)

