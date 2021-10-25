# 环形链表

#### *Linked List Cycle*

给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。

 

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？


英文题目:

Given `head`, the `head` of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

 

**example 1**
![test 1](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/60.%20Linked%20List%20Cycle(Easy)/circularlinkedlist.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

```


**example 2**
![test 2](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/60.%20Linked%20List%20Cycle(Easy)/circularlinkedlist_test2.png)

```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

```

**example 3**
![test 3](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/60.%20Linked%20List%20Cycle(Easy)/circularlinkedlist_test3.png)

```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

```


---

### 思路

1. 两个指针差速向前遍历，p1走一步，p2走两步，如果存在环形链路，则p2会从后面追上p1
    

### 代码
```

/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        ListNode *p1, *p2;
        p1 = p2 = head;
        while (p2->next != nullptr && p2->next->next != nullptr)
        {
            p2 = p2->next->next;
            p1 = p1->next;
            if (p2 == p1)
                return true;
        }
        return false;
    }
};

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)