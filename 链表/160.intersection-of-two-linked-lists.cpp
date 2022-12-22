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

