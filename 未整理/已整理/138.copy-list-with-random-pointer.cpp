/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* backup = new Node(0);
        Node* p = backup;
        unordered_map<Node*, int> m;
        vector<Node*> b;
        Node* h = head;
        for (int i = 0; h != nullptr; i++)
        {
            p->next = new Node(h->val);
            b.push_back(p->next);
            pair<Node*, int> a;
            a.first = h;
            a.second = i;
            m.insert(a);
            p = p->next;
            h = h->next;
        }
        p = backup->next;
        h = head;
        for (int i = 0; h != nullptr; i++)
        {
            if (h->random != nullptr)
            {
                int which = m[h->random];
                p->random = b[which];
            }
            p = p->next;
            h = h->next;
        }
        return backup->next;
    }
};
// @lc code=end

