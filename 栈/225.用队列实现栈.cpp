/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    MyStack() {
        q1 = &queue1;
        q2 = &queue2;
    }
    
    void push(int x) {
        q1->push(x);
        while (!q2->empty()) {
            q1->push(q2->front());
            q2->pop();
        }
        queue<int>* tmp = q1;
        q1 = q2;
        q2 = tmp;
    }
    
    int pop() {
        int a = q2->front();
        q2->pop();
        return a;
    }
    
    int top() {
        return q2->front();
    }
    
    bool empty() {
        return q1->empty() && q2->empty();
    }

private:
    queue<int> queue1; // 1 2 3 4 5
    queue<int> queue2;
    queue<int>* q1;
    queue<int>* q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

