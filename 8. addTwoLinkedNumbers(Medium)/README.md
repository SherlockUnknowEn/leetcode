# 两个链表数字相加
#### *Add Two Numbers*

* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

* You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**example**
```
Input: (2 -> 6) + (3 -> 7)
Output: 1 -> 3 -> 5
```
### 思路
1. 将链表整体转成str，再reverse
2. reverse之后转成int相加，得到re
3. re再次reverse之后，循环转成链表


### 代码
```
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
```