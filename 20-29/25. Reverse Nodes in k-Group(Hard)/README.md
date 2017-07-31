# k组倒置链表节点
#### *Reverse Nodes in k-Group*

* 给定一个链表，每k个倒置其节点，返回新链表的头部，不允许使用额外的内存，只能在原有链表节点基础上进行操作。

题目原文:

* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* k is a positive integer and is less than or equal to the length of the linked list.
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
* You may not alter the values in the nodes, only nodes itself may be changed.
* Only constant memory is allowed.



**example 1**
```
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
```

---

### 思路

1. 参照我的博文[成对交换链表节点](http://blog.csdn.net/github_37953781/article/details/76094045)，讨巧的办法是只交换节点内的value，不做节点的移动。
2. 如不使用上述方法，可以使用递归完成


 
### 代码
```
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
```