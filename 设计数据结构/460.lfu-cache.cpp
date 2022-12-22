/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

class Node {
public:
    int key;
    int val;
    Node* pre;
    Node* next;
};

class DoubleList {
public:
    DoubleList() {
        this->head = new Node();
        this->tail = new Node();
        head->next = tail;
        tail->pre = head;
        this->size = 0;
    }

    void removeNode(Node* n)
    {
        n->pre->next = n->next;
        n->next->pre = n->pre;
        this->size--;
    }

    void addFirst(Node* n)
    {
        n->next = head->next;
        n->pre = head;
        head->next->pre = n;
        head->next = n;
        this->size++;
    }

    Node* removeLast() {
        if (tail->pre == head)
            return nullptr;
        
        Node* n = tail->pre;
        removeNode(n);
        return n;
    }

    void addFirst(int key, int value)
    {
        Node* n = new Node();
        n->key = key;
        n->val = value;
        addFirst(n);
    }

    int length() {
        return this->size;
    }

private:
    Node* head;
    Node* tail;
    
    int size;
};

// @lc code=start
class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (key2val.find(key) == key2val.end())
            return -1;
        int value = key2val[key];
        this->put(key, value);
    }
    
    void put(int key, int value) {
        // 添加
        // if (key2val->find(key) == key2val.end())
        // {
        //     if (key2val.size() == capacity)
        //     {
        //         // 删除一个 再添加
        //         DoubleList list = freq2key[minFreq];
        //         Node* n = list.removeLast();
        //         if (list.length() == 0)
        //             freq2key.erase(minFreq);
        //         key2val.erase(n->key);
        //         key2freq.erase(n->key);
        //     }
        //     DoubleList list = freq2key[minFreq];
        //     list.addFirst(key, value);

        //     key2val.insert({ key, value });
        //     key2freq.insert({ key, 1 });
        //     minFreq = 1;
        // }
        // else
        // {
        //     key2val[key] = value;
        //     key2freq[key] += 1;
        //     DoubleList list = freq2key[minFreq];
        //     list.update(key, value);
        //     minFreq = min(minFreq, key2freq[key]);
        // }
    }

private:
    unordered_map<int, int> key2val;
    unordered_map<int, int> key2freq;
    unordered_map<int, DoubleList> freq2key;

    int minFreq;
    int capacity;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

