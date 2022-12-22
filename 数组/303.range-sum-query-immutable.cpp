/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        data.clear();
        data.insert(data.begin(), nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            data[i+1] = data[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return data[right + 1] - data[left];
    }
private:
    vector<int> data;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

