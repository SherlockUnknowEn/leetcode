/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

class Node {
public:
    Node* pre;
    Node* next;
    int val;
    int key;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node();
        this->tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (map.find(key) == map.end())
        {
            return -1;
        }
        else
        {
            int value = map[key]->val;
            this->put(key, value); // 利用put方法把数据提前
            return map[key]->val;
        }
    }
    
    void put(int key, int value) {
        if (map.find(key) == map.end())
        {
            if (map.size() == this->capacity)
            {
                // 删除末尾一个
                Node* n = tail->pre;
                removeNode(n);
                map.erase(n->key);
            }
        }
        else
        {
            Node* n = map[key];
            removeNode(n);
            map.erase(n->key);
        }
        Node* n = new Node();
        n->key = key;
        n->val = value;
        addFirst(n);
        map.insert({ key, n });
    }

    void removeNode(Node* n)
    {
        n->pre->next = n->next;
        n->next->pre = n->pre;
    }

    void addFirst(Node* n)
    {
        n->next = head->next;
        n->pre = head;
        head->next->pre = n;
        head->next = n;
    }

private:
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

