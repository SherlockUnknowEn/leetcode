# 链表的中间结点

#### *Middle of the Linked List*

给定一个头结点为 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

提示：

给定链表的结点数介于 1 和 100 之间。


英文题目:

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the `second middle` node.

 

**example 1**

![test 1](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/63.%20Middle%20of%20the%20Linked%20List(Easy)/lc-midlist1.jpg)

```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

```


**example 2**

![test 2](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/63.%20Middle%20of%20the%20Linked%20List(Easy)/lc-midlist2.jpg)

```
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

```



**Constraints:**

The number of nodes in the list is in the range `[1, 100]`.

1 <= `Node.val` <= 100

---

### 思路

1. 使用快慢两个指针，快指针每次走2步，慢指针每次走1步，当快指针到达链表尾部时，慢指针指向链表中点
2. 注意处理链表长度为偶数的情况


### 代码
```

/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 偶数个
        if (fast->next != nullptr && fast->next->next == nullptr)
            return slow->next;
        else 
            return slow;        
    }
};
// @lc code=end


```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)