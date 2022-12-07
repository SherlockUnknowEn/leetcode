/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> visited;
        queue<Node*> qe;
        qe.push(node);
        Node* ans = new Node(node->val);
        visited[node] = ans;

        while (!qe.empty()) {
            Node* n = qe.front();
            qe.pop();

            vector<Node*> v = n->neighbors;
            for (auto& item : v) {
                if (visited.find(item) == visited.end()) {
                    // cout << "?? " << v[i]->val << " ";
                    Node* tmp = new Node(item->val);
                    visited[item] = tmp;
                    qe.push(item);
                }
                visited[n]->neighbors.push_back(visited[item]);
            }
        }
        return ans;;
    }
};
// @lc code=end

