/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 记录num的出现次数
        unordered_map<int, int> counting;
        for (int a : nums) {
            counting[a]++;
        }
        // 小顶堆，前 k 个频次最高的num
        // &Solution::cmp 类型为 void (*ptr)(const pair<int, int>&, const pair<int, int>&)
        // decltype(&Solution::cmp) 获取Solution::cmp函数的声明类型
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&Solution::cmp)> heap(Solution::cmp);
        for (auto& kv : counting) {
            if (heap.size() < k)
                heap.push(kv);
             else if (heap.size() >= k && kv.second >= heap.top().second) {
                heap.push(kv);
                heap.pop();
            }
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }

};
// @lc code=end

