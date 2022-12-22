/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        if (freq.find(val) == freq.end())
            freq.insert({ val, 0 });
        freq[val] += 1;
        data.push_back(val);        
        maxFreqKey = freq[maxFreqKey] > freq[val] ? maxFreqKey : val;
    }
    
    int pop() {
        if (data.size() <= 0)
            return -1;
        
        int val = maxFreqKey;
        int pos = findEnd(data, val);
        data.erase(data.begin() + pos);
        freq[maxFreqKey] -= 1;
        // data 从后往前遍历，寻找靠近栈顶的 最大freq
        maxFreqKey = data[data.size() - 1];
        for (int i = data.size() - 1; i >= 0; i--)
        {
            maxFreqKey = freq[data[i]] > freq[maxFreqKey] ? data[i] : maxFreqKey;
        }
        return val; 
    }

    int findEnd(const vector<int>& data, int val)
    {
        for (int i = data.size() - 1; i >= 0; i--)
        {
            if (data[i] == val)
                return i;
        }
        return -1;
    }
private:
    unordered_map<int, int> freq; // key:data  value: count
    vector<int> data;
    int maxFreqKey;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

