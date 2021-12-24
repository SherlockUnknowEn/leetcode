# 分隔链表

#### *Patition List*

给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。




英文题目:

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.



**Constraints:**

- The number of nodes in the list is in the range `[0, 200]`.
- `-100 <= Node.val <= 100`
- `-200 <= x <= 200`

**example 1**

![example 1](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/66.%20Partition%20List(Medium)/partition.jpg)

```
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```

**example 2**

```
Input: head = [2,1], x = 2
Output: [1,2]
```



---

### 思路

1. 使用`less`和`greater`两个指针，遍历链表时，大于等于`x`的元素插入在`less`后，小于等于`x`的插入`greater`后，完成遍历后，将`greater`插入`less`后即可
2. 避免链表出现环，注意处理`greater`，遍历完成后让`greater->next = nullptr`


### 代码
```cpp

/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode less_g;
        ListNode greater_g;
        ListNode *less = &less_g;
        ListNode *greater = &greater_g;

        while (head != nullptr)
        {
            if (head->val >= x)
            {
                greater->next = head;
                greater = greater->next;
            }
            else
            {
                less->next = head;
                less = less->next;
            }
            head = head->next;
        }
        greater->next = nullptr;
        less->next = greater_g.next;
        return less_g.next; 
    }
};
// @lc code=end
```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)