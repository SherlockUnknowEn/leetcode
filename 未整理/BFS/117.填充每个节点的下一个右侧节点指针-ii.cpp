/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> qe;
        qe.push(root);
        while (!qe.empty()) {
            int sz = qe.size();
            Node* next = nullptr;
            for (int i = 0; i < sz; i++) {
                Node* n = qe.front();
                qe.pop();
                n->next = next;
                next = n;
                if (n->right != nullptr)
                    qe.push(n->right);
                if (n->left != nullptr)
                    qe.push(n->left);
            }
        }
        return root;
    }
};
// @lc code=end

