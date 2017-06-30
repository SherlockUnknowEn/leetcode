# 移除链表倒数第n个元素
#### *Remove Nth Node From End of List*

* 给定一个链表，移除倒数第n个元素，返回链表头部。
* Given a linked list, remove the nth node from the end of list and return its head.

Note:
Given n will always be valid.
Try to do this in one pass.


**example 1**

```
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
```

**example 2**
```
Given linked list: 1, and n = 1.
output: None
```

**example 3**
```
Given linked list: 1->2->3, and n = 3.
output: 2->3
```

### 思路
1. 两个指针，`fast`和`slow`，`fast`指向`slow`之后n个位置，同步移动`fast`和`slow`，当`fast.next`为null的时候，`slow.next`即为要移除的那个元素，只需要`slow.next = slow.next.next`即可，时间复杂度O(n)
2. 注意考虑`n`为链表长度的情况，即移除首个元素 


### 代码
```
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
```