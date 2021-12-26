# 复制带随机指针的链表

#### *Copy List with Random Pointer*

给你一个长度为 `n` 的链表，每个节点包含一个额外增加的随机指针 `random` ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 **深拷贝**。 深拷贝应该正好由 `n` 个 **全新** 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 `next` 指针和 `random` 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。**复制链表中的指针都不应指向原链表中的节点** 。

例如，如果原链表中有 `X` 和`Y `两个节点，其中 `X.random --> Y` 。那么在复制链表中对应的两个节点 `x` 和 `y` ，同样有 `x.random --> y` 。

返回复制链表的头节点。

用一个由 `n` 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 `[val, random_index]` 表示：

* `val`：一个表示 `Node.val` 的整数。
* `random_index`：随机指针指向的节点索引（范围从 `0` 到 `n-1`）；如果不指向任何节点，则为  `null` 。
  你的代码 **只** 接受原链表的头节点 `head` 作为传入参数。




英文题目:

A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a **deep copy** of the list. The deep copy should consist of exactly `n` **brand new** nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. **None of the pointers in the new list should point to nodes in the original list**.

For example, if there are two nodes X and Y in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of `[val, random_index]` where:

* `val`: an integer representing `Node.val`
* `random_index`: the index of the node (range from `0` to `n-1`) that the random pointer points to, or `null` if it does not point to any node.
    Your code will **only** be given the head of the original linked list.



**Constraints:**

- The number of nodes in the list is in the range `[0, 200]`.
- `-100 <= Node.val <= 100`
- `-200 <= x <= 200`

**example 1**

![example 1](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/67.%20Copy%20List%20with%20Random%20Pointer(Medium)/e1.png)

```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

**example 2**

![example 2](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/67.%20Copy%20List%20with%20Random%20Pointer(Medium)/e1.png)

```
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```

**example 3**

![example 3](https://github.com/SherlockUnknowEn/leetcode/blob/master/60-69/67.%20Copy%20List%20with%20Random%20Pointer(Medium)/e3.png)

```
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```



---

### 思路

1. 使用`map`存储原链表中每个节点`地址`(key)和其在表中的`序号`(value)
2. 先遍历原链表，复制每个节点`val`和`next`，将新节点存入数组`b`
3. 再次遍历原链表，可从`map`中查询到该节点的`random`节点的序号`i`，`b[i]`即为对应新节点的`random`需要指向的位置
4. 注意处理`null`值


### 代码
```cpp

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
```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)