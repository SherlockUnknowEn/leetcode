/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        data.push(val);
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        int a = data.top();
        data.pop();
        return a;
    }
    
    int getMin() {

    }

private:
    stack<int> data;
    stack<int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

