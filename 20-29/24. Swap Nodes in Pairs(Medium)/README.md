# 成对交换链表节点
#### *Swap Nodes in Pairs*

* 给定一个链表，成对交换两个节点，返回新链表的头部，不允许使用额外的内存，只能在原有链表节点基础上进行操作。
* Given a linked list, swap every two adjacent nodes and return its head.

* For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

* Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.



**example 1**
```
input: 1 -> 2 -> 3 -> 4

output: 2 -> 1 -> 4 -> 3
```

---

### 思路

1. 可以使用两个指针，指向当前需要交换的两个节点，交换之后向链表尾部移动。
2. 交换节点是一种方法，另外一种取巧的方法是，不交换节点，只交换节点的值


 
### 代码
```
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        try:
            prev = head
            tail = prev.next
            while True:
                prev.val, tail.val = tail.val, prev.val
                prev = tail.next
                tail = prev.next
        finally:
            return head
```