# -*- coding: utf-8 -*-
# @Time    : 2017/7/31 下午4:50
# @Author  : fj
# @Site    : 
# @File    : Reverse Nodes in k-Group.py
# @Software: PyCharm

# Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
#
# k is a positive integer and is less than or equal to the length of the linked list.
# If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
#
# You may not alter the values in the nodes, only nodes itself may be changed.
#
# Only constant memory is allowed.
#
# For example,
# Given this linked list: 1->2->3->4->5
#
# For k = 2, you should return: 2->1->4->3->5
#
# For k = 3, you should return: 3->2->1->4->5


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        try:
            arr = []
            tmp = head
            self.k = k
            for i in range(k):
                arr.append(tmp)
                tmp = tmp.next
            while True:
                for i in range(k//2):
                    arr[i].val, arr[-1-i].val = arr[-1-i].val, arr[i].val
                arr = list(map(self.move, arr))
        finally:
            return head

    def move(self, x):
        ret = x
        for i in range(self.k):
            ret = ret.next
        return ret




head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
# head.next.next.next = ListNode(4)
# head.next.next.next.next = ListNode(5)

a = Solution().reverseKGroup(head, 2)

print(a.next.val)
