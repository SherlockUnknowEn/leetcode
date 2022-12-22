/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int l_max = 0;
        int r_max = 0;
        int res = 0;
        while (start <= end) {
            l_max = max(l_max, height[start]);
            r_max = max(r_max, height[end]);
            if (l_max < r_max) {
                res += (l_max - height[start]);
                start++;
            } else {
                res += (r_max - height[end]);
                end--;
            }
        }
        return res;
    }

    int trap2(vector<int>& height) {
        int sum = 0;
        int n = height.size();
        vector<int> leftHeight(n);
        vector<int> rightHeight(n);
        leftHeight[0] = height[0];
        rightHeight[n-1] = height[n-1];
        for (int i = 1; i < n; i++)
        {
            leftHeight[i] = max(leftHeight[i-1], height[i]);
        }
        for (int i = n-2; i >= 0; i--)
        {
            rightHeight[i] = max(rightHeight[i+1], height[i]);
        }
        
        for (int i = 1; i < n-1; i++)
        {
            sum = sum + min(leftHeight[i], rightHeight[i]) - height[i];
        }
        return sum;
    }

};
// @lc code=end

