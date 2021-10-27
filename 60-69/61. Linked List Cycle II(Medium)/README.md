# 环形链表2

#### *Linked List Cycle II*

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以使用 O(1) 空间解决此题？


英文题目:

Given the `head` of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, `pos` is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is `-1` if there is no cycle. Note that `pos` is not passed as a parameter.

Do not modify the linked list.

 

**example 1**
![test 1](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/61.%20Linked%20List%20Cycle%20II(Medium)/circularlinkedlist.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

```


**example 2**
![test 2](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/61.%20Linked%20List%20Cycle%20II(Medium)/circularlinkedlist_test2.png)

```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

```

**example 3**
![test 3](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/61.%20Linked%20List%20Cycle%20II(Medium)/circularlinkedlist_test3.png)

```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

```


**Constraints:**

The number of the nodes in the list is in the range [0, 104].

-105 <= Node.val <= 105

pos is -1 or a **valid index** in the linked-list.


---

### 思路

1. 参照[Linked List Cycle](https://github.com/SherlockUnknowEn/leetcode/tree/master/60-69/60.%20Linked%20List%20Cycle(Easy))可判断链表是否有环
2. 若链表有环，在相遇处让其中一个指针指向头节点`head`后，两个指针同时前进，再次相遇的节点即为环的起始节点
3. 具体原理如下图
![img](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/61.%20Linked%20List%20Cycle%20II(Medium)/2.jpeg)


### 代码
```

/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            // 有环
            if (fast == slow)
            {
                // slow 从head从新走，相遇即为环起点
                slow = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
// @lc code=end


```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)