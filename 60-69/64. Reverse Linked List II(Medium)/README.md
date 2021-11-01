# 反转链表 II

#### *Reverse Linked List II*

给你单链表的头指针 `head` 和两个整数 `left` 和 `right` ，其中 `left <= right` 。请你反转从位置 `left` 到位置 `right` 的链表节点，返回 反转后的链表 。

提示：

给定链表的结点数介于 1 和 100 之间。


英文题目:

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= n <= 500`
- `-500 <= Node.val <= 500`
- `1 <= left <= right <= n`

**example 1**

![example 1](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/64.%20Reverse%20Linked%20List%20II(Medium)/rev2ex2.jpg)

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
```

**example 2**

```
Input: head = [5], left = 1, right = 1
Output: [5]
```



---

### 思路

1. 递归法：为`head`节点编号为1时，反转`[left, right]`之间的节点。当第二个节点(`head->next`)编号为1时，题目相当于反转`[left-1, right-1]`之间的节点。当第`left`个节点编号为1时，题目相当于反转**前`right - left`个**节点。
2. 反转前`N`个节点的算法，由`reverseN(ListNode* head, int N)`函数给出
3. 头插法：设`g`为`left`左边的节点，`p`从`left`节点移动到`right`，`p`遍历过程使用**头插法**插入到`g`后，即可实现倒序


### 代码
```cpp

/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 递归法
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1)
            // 如果从表头开始反转，相当于反转前N个节点
            return reverseN(head, right);
        // 对于 head->next 相当于反转区间为 [left - 1, right - 1]
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }

    ListNode* N1_node;

    ListNode* reverseN(ListNode* head, int N) {
        if (N == 1)
        {
            N1_node = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, N - 1);
        head->next->next = head;
        // head->next = nullptr; // 全链表翻转时,原先的头节点变为尾节点，next指向null
        head->next = N1_node; // 反转前N个节点时，原先的头结点next指向第 N+1 个
        return last;
    }

    // 头插法
    ListNode* reverseBetween2(ListNode* head, int left, int right) {
        ListNode *dummy;
        dummy->next = head;
        ListNode *g = dummy, *p = dummy->next;
        
        for (size_t i = 0; i < left; i++)
        {
            g = g->next;
            p = p->next;
        }
        for (size_t i = 0; i < right - left; i++)
        {
            ListNode *tmp = p->next;
            p->next = p->next->next;
            tmp->next = g->next;
            g->next = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)