/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        return subNums(1, n);
    }

    int subNums(int left, int right) {
        
        
        if (left >= right)
            return 1;
        int key = right - left + 1;
        if (map.find(key) != map.end())
        {
            return map[key];
        }
        int sum = 0;
        for (size_t i = left; i < right+1; i++)
        {
            int lo = subNums(left, i-1);
            int ri = subNums(i+1, right);
            sum += lo * ri;
        }
        map.insert({ key, sum });
        return sum;
    }

private:
    unordered_map<int, int> map;
};
// @lc code=end

