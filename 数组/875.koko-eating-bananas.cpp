/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxval = piles[0];
        // 计算最大值piles中的最大值，时间复杂度 O(n)
        // 直接取上下限反而时间复杂度低
        int left = 1;
        int right = 1000000000;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (f(piles, mid) == h)
            {
                right = mid - 1;
            }
            else if (f(piles, mid) > h)
            {
                left = mid + 1; // 因为 f 单调递减,  所以 左边界改变
            }
            else if (f(piles, mid) < h)
            {
                right = mid - 1;
            }
        }
        return left;
    }

private:
    int f(const vector<int>& piles, int k)
    {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            sum += piles[i] % k == 0 ? piles[i] / k : piles[i] / k + 1;
        }
        return sum;
    }
};
// @lc code=end

