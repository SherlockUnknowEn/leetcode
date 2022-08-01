/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> presum(n+1);

    //     for (int i = 1; i < n+1; i++)
    //     {
    //         presum[i] = presum[i-1] + nums[i-1];
    //     }
    //     int count = 0;
    //     for (int i = 1; i < n+1; i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (presum[i] - presum[j] == k)
    //                 count++;
    //         }
            
    //     }
    //     return count;        
    // }


    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n+1);
        unordered_map<int, int> cc;
        int count = 0;
        // base case
        cc.insert({ 0, 1 });
        for (int i = 1; i < n+1; i++)
        {
            presum[i] = presum[i-1] + nums[i-1];
            int key = presum[i] - k;
            count += cc[key];
            if (cc.find(presum[i]) == cc.end())
            {
                cc.insert({ presum[i], 0 });
            }
            cc[presum[i]] += 1;
            
        }
        return count;        
    }
};
// @lc code=end

