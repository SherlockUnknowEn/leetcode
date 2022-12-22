/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort(g.begin(), g.end());
        // sort(s.begin(), s.end());
        // int sum = 0;
        // int gidx = g.size() - 1;
        // for (int i = s.size() - 1; i >= 0; i--)
        // {
        //     for (int j = gidx; j >= 0; j--)
        //     {
        //         if (s[i] >= g[j])
        //         {
        //             sum++;
        //             gidx = j - 1;
        //             break;
        //         }                
        //     }            
        // }
        // return sum;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 饼干数组的下标
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) { // 优先满足最大胃口的孩子
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;
    }
};
// @lc code=end

