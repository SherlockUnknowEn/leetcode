/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (val2index.find(val) != val2index.end())
        {
            return false;
        }
        int index = data.size();
        data.push_back(val);
        val2index.insert({ val, index });
        return true;
    }
    
    bool remove(int val) {
        if (val2index.find(val) == val2index.end())
        {
            return false;
        }
        int index = val2index[val];
        int tail_val = data[data.size() - 1];
        data[index] = tail_val;
        val2index[tail_val] = index;

        val2index.erase(val);
        data.pop_back();
        return true;
    }
    
    int getRandom() {
        return data[rand() % data.size()];
    }

private:
    unordered_map<int, int> val2index;
    vector<int> data;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

