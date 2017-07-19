# -*- coding: utf-8 -*-
# @Time    : 2017/7/19 上午9:14
# @Author  : fj
# @Site    : 
# @File    : Merge k Sorted Lists.py
# @Software: PyCharm

# Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __cmp__(self, other):
        return self.val <= other

class Solution(object):

    def mergeKLists_new(self, links):
        """
        :type links: List[ListNode]
        :rtype: ListNode
        """
        head = None
        for i in links:
            head = self.mergeTwoLists(head, i)
        return head


    # 为了方便阅读，给出之前的代码
    # from mergeTwoLists，《合并两个已排序链表》的代码
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


    def mergeKLists_old(self, links):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        i = 0
        while i < len(links):
            if not links[i]:
                links.pop(i)
                i -= 1
            i += 1
        if not links:
            return
        head = links[0]
        idx = 0
        for i in range(len(links)):
            if head.val > links[i].val:
                head = links[i]
                idx = i
        tmp = head
        if links[idx].next:
            links[idx] = links[idx].next
        else:
            links.pop(idx)
        while len(links) > 0:
            min = links[0]
            idx = 0
            for i in range(len(links)):
                if (min.val > links[i].val):
                    min = links[i]
                    idx = i
            tmp.next = min
            tmp = tmp.next
            if links[idx].next:
                links[idx] = links[idx].next
            else:
                links.pop(idx)
        return head

b = ListNode(1)
b1 = ListNode(2)
b2 = ListNode(5)
a = Solution().mergeKLists_new([None,b1])
print(a.val)
