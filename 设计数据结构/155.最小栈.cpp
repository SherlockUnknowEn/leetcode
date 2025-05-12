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
        if (minv.empty()) {
            minv.push(val);
        } else {
            minv.push(min(val, minv.top()));
        }
        data.push(val);
    }
    
    void pop() {
        data.pop();
        minv.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minv.top();
    }

private:
    // 我们只需要设计一个数据结构，使得每个元素 a 与其相应的最小值 m 时刻保持一一对应
    stack<int> data;
    stack<int> minv;
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

