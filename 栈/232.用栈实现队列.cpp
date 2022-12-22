/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {
        st1 = &stack1;
        st2 = &stack2;
    }
    
    void push(int x) {
        st1->push(x);
    }
    
    int pop() {
        if (st2->empty()) {
            pull1to2();
        }
        int a = st2->top();
        st2->pop();
        return a;
    }
    
    int peek() {
        if (st2->empty()) {
            pull1to2();
        }
        return st2->top();
    }
    
    bool empty() {
        return st1->empty() && st2->empty();
    }
private:

    void pull1to2() {
        while (!st1->empty()) {
            st2->push(st1->top());
            st1->pop();
        }
    }

    stack<int> stack1; // 4 2 3
    stack<int> stack2; // 3 2 

    stack<int>* st1;
    stack<int>* st2;
};
// ["MyQueue","push","push","push","push","pop","push","pop","pop","pop","pop"]\n[[],[1],[2],[3],[4],[],[5],[],[],[],[]]\n
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

