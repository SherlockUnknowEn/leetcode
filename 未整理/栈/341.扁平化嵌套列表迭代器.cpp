/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->ans = flatten(nestedList);
        this->idx = 0;
    }
    
    int next() {
        return ans[idx++];
    }
    
    bool hasNext() {
        return idx < ans.size();
    }
private:
    vector<int> ans;
    int idx;

    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> ans;
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
                ans.push_back(nestedList[i].getInteger());
            else
            {
                // cout << i << " ";
                vector<int> v = flatten(nestedList[i].getList());
                ans.insert(ans.end(), v.begin(), v.end());
            }
        }
        return ans;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

