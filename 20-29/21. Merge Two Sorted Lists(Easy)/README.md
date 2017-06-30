# 合并两个已排序的链表
#### *Merge Two Sorted Lists*

* 合并两个已排序的链表，新链表中的每个节点必须是来自输入的两个链表的节点（即不能构造新的节点），返回新链表的头部。
* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

**example 1**
```
input: 1->2->4, 3->8
output: 1->2->3->4->8
```

---

### 思路

1. `head`指向输入两个链表中头节点较小值，作为新链表的头部
2. `tail`指向新链表表尾，初始状态`head = tail`
3. `a`扫描`l1`，b扫描`l2`，比较`a`和`b`节点内值的大小，将较小的加入`tail`之后，`a`和`b`中较小的向后移动一个节点，较大的不动，tail向后移动一个节点保证任意时候指向都是新链表尾部
4. `l1`和`l2`其中一个已经遍历完，若另一个还有元素，添加到`tail`之后

 
### 代码
```
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
```
