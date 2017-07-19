# 合并n个已排序的链表
#### *Merge k Sorted Lists*

* 合并n个已排序的链表，新链表中的每个节点必须是来自输入的原链表的节点（即不能构造新的节点），返回新链表的头部。
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.



**example 1**
```
input:
[
  3->5->8,
  2->11>12,
  4->8,
]
output:
2->3->4->5->8->8->11->12
```

---

### 思路

1. 参照本人之前已发表的[《合并两个已排序的链表》](http://blog.csdn.net/github_37953781/article/details/73995174)，只需要将此算法应用n-1次即可得到新链表。


 
### 代码
```
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
```
