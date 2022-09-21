/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 *
 * [1670] 设计前中后队列
 */

// @lc code=start
struct Node {
    int val;
    Node* next;
    Node* pre;
    Node(int val): val(val), pre(nullptr), next(nullptr) {  }
    Node(): val(-1), pre(nullptr), next(nullptr) { }
};

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        // cout << "pushFront" << endl;
        if (q1.size() > q2.size())
        {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        q1.push_front(val);
        // printt();
    }
    
    void pushMiddle(int val) {
        // cout << "pushMiddle" << endl;
        if (q1.size() > q2.size()) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        q1.push_back(val);
        // printt();
    }

    void pushBack(int val) {
        // cout << "pushBack" << endl;
        if (q2.size() > q1.size()) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        q2.push_back(val);
        // printt();
    }

    int popFront() {
        // cout << "popFront" << endl;
        if (q1.size() + q2.size() == 0)
            return -1;
        if (q1.size() == 0)
        {
            int t = q2.front();
            q2.pop_front();
            return t;
        }

        int t = q1.front();
        if (q1.size() <= q2.size()) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        q1.pop_front();
        // printt();
        return t;
    }
    
    int popMiddle() {
        // cout << "popMiddle" << endl;
        if (q1.size() + q2.size() == 0)
            return -1;
        int t = -1;
        if (q1.size() >= q2.size()) {
            t = q1.back();
            q1.pop_back();
        }
        else {
            t = q2.front();
            q2.pop_front();
        }
        // printt();
        return t;
    }
    
    int popBack() {
        // cout << "popBack" << endl;
        if (q1.size() + q2.size() == 0)
            return -1;

        if (q2.size() == 0)
        {
            int t = q1.back();
            q1.pop_back();
            return t;
        }

        int t = q2.back();
        if (q1.size() > q2.size()) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        q2.pop_back();
        // printt();
        return t;
    }

    // void printt() {
    //     cout << "q1: ";
    //     for (auto a: q1) {
    //         cout << a << " ";
    //     }
    //     cout << " q2: ";
    //     for (auto a: q2) {
    //         cout << a << " ";
    //     }
    //     cout << endl;
    // }

private:
    deque<int> q1;
    deque<int> q2;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end

