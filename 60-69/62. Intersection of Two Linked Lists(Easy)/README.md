# 相交链表

#### *Intersection of Two Linked Lists*

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。

图示两个链表在节点 `c1` 开始相交：

![160_statement.png](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/62.%20Intersection%20of%20Two%20Linked%20Lists(Easy)/160_statement.png)

题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须保持其原始结构。


提示：

`listA` 中节点数目为 `m`
`listB` 中节点数目为 `n`
0 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA <= m
0 <= skipB <= n
如果 `listA` 和 `listB` `没有交点，intersectVal` 为 `0`
如果 `listA` 和 `listB` 有交点，intersectVal == listA[skipA + 1] == listB[skipB + 1]
 


英文题目:

Given the heads of two singly linked-lists `headA` and `headB`, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return `null`.

For example, the following two linked lists begin to intersect at node `c1`:

![160_statement.png](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/62.%20Intersection%20of%20Two%20Linked%20Lists(Easy)/160_statement.png)

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

**Note** that the linked lists must **retain their original** structure after the function returns.

Custom Judge:

The inputs to the **judge** are given as follows (your program is **not** given these inputs):

`intersectVal` - The value of the node where the intersection occurs. This is 0 if there is no intersected node.

`listA` - The first linked list.

`listB` - The second linked list.

`skipA` - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.

`skipB` - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.

The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be **accepted**.

 

**example 1**

![160_example_1.png](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/62.%20Intersection%20of%20Two%20Linked%20Lists(Easy)/160_example_1.png)


```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

```


**example 2**

![160_example_2.png](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/62.%20Intersection%20of%20Two%20Linked%20Lists(Easy)/160_example_2.png)


```
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

```

**example 3**

![160_example_3.png](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/62.%20Intersection%20of%20Two%20Linked%20Lists(Easy)/160_example_3.png)


```
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

```


**Constraints:**

The number of nodes of listA is in the m.

The number of nodes of listB is in the n.

0 <= m, n <= 3 * 104

1 <= Node.val <= 105

0 <= skipA <= m

0 <= skipB <= n

intersectVal is 0 if listA and listB do not intersect.

intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.



---

### 思路

1. 解决这个问题的关键是，通过某些方式，让 `p1` 和 `p2` 能够同时到达相交节点 `c1`
2. 我们可以让 `p1` 遍历完链表 `A` 之后开始遍历链表 `B`，让 `p2` 遍历完链表 `B` 之后开始遍历链表 `A`，这样相当于「逻辑上」两条链表接在了一起。如果这样进行拼接，就可以让 `p1` 和 `p2` 同时进入公共部分，也就是同时到达相交节点 `c1`
3. 具体原理如下图

![img](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/62.%20Intersection%20of%20Two%20Linked%20Lists(Easy)/2.jpeg)


### 代码
```

/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode *pA = headA;
        // ListNode *pB = headB;
        // bool AtoB = false;
        // bool BtoA = false;
        // while (pA != nullptr && pB != nullptr)
        // {
        //     pA = pA->next;
        //     pB = pB->next;
        //     if (pA == nullptr && !AtoB)
        //     {
        //         pA = headB;
        //         AtoB = true;
        //     }
        //     if (pB == nullptr && !BtoA)
        //     {
        //         pB = headA;
        //         BtoA = true;
        //     }
                
        //     if (pA == pB)
        //         return pA;
        // }
        // return nullptr;


        // p1 指向 A 链表头结点，p2 指向 B 链表头结点
        ListNode *p1 = headA, *p2 = headB;
        // p1 和 p2 同时走到链表尾部，null时    null == null 跳出循环，代表无交叉点
        while (p1 != p2) {
            // p1 走一步，如果走到 A 链表末尾，转到 B 链表
            if (p1 == nullptr)
                p1 = headB;
            else            
                p1 = p1->next;
            // p2 走一步，如果走到 B 链表末尾，转到 A 链表
            if (p2 == nullptr) 
                p2 = headA;
            else            
                p2 = p2->next;
        }
        return p1;
    }
};
// @lc code=end




```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)