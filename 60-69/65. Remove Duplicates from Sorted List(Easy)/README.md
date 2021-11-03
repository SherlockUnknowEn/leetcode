# 删除链表中的重复元素

#### *Remove Duplicates from Sorted List*

存在一个按升序排列的链表，给你这个链表的头节点 `head` ，请你删除所有重复的元素，使每个元素 **只出现一次** 。

返回同样按升序排列的结果链表。


英文题目:

Given the `head` of a sorted linked list, *delete all duplicates such that each element appears only once*. Return *the linked list **sorted** as well*.



**Constraints:**

- The number of nodes in the list is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is guaranteed to be **sorted** in ascending order.

**example 1**

![example 1](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/65.%20Remove%20Duplicates%20from%20Sorted%20List(Easy)/list1.jpeg)

```
Input: head = [1,1,2]
Output: [1,2]
```

**example 2**

![example 1](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/65.%20Remove%20Duplicates%20from%20Sorted%20List(Easy)/list2.jpeg)

```
Input: head = [1,1,2,3,3]
Output: [1,2,3]
```



---

### 思路

1. `d`指针指向第一个元素，`p`指针遍历链表，过程中有
2. 当`p->val == d->val`时，表明遇到了相同值，`d`不动，`p`继续遍历
3. 当`p->val != d->val`时，令`d->next = p; d = d->next;`
4. 注意处理最后一个重复节点即可


### 代码
```cpp

/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-999);
        ListNode *d = dummy;
        dummy->next = head;
        ListNode *p = head;
        while (p != nullptr)
        {
            if (d->val != p->val)
            {
                d->next = p;
                d = p;
            }
            p = p->next;
        }
        d->next = p; // 最后一个重复的节点删除
        return dummy->next;
    }
};
// @lc code=end

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)