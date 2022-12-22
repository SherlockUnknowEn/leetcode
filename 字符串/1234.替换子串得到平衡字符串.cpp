/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> memo;
        for (int i = 0; i < s.size(); i++) {
            memo[s[i]]++;
        }
        int avg = s.size() / 4;
        unordered_map<char, int> need;
        if (memo['A'] > avg) need['A'] = memo['A'] - avg;
        if (memo['S'] > avg) need['S'] = memo['S'] - avg;
        if (memo['D'] > avg) need['D'] = memo['D'] - avg;
        if (memo['F'] > avg) need['F'] = memo['F'] - avg;
        int len = need['A'] + need['S'] + need['D'] + need['F'];
        if (len == 0) return 0;
        // 滑动窗口法
        int left = 0, right = 0;
        unordered_map<char, int> window; // 记录窗口里字符个数
        int ans = s.size();
        for (; right < s.size(); right++) // right++ 扩大窗口 
        {
            window[s[right]]++; // 新字符入窗
            while (window['A'] >= need['A'] 
                && window['S'] >= need['S'] 
                && window['D'] >= need['D'] 
                && window['F'] >= need['F']) // 符合条件，缩小窗口直到不符合
            {
                ans = min(ans, right - left + 1);
                window[s[left]]--;
                left++; // 缩小窗口, 窗口左边界右移
            }
        }
        
        return ans;
    }







    int balancedString(string s) {
        unordered_map<char, int> memo;
        for (int i = 0; i < s.size(); i++) {
            memo[s[i]]++;
        }
        int avg = s.size() / 4;
        unordered_map<char, int> need;
        // 大于 size / 4 的需要变成别的字符
        if (memo['A'] > avg) need['A'] = memo['A'] - avg;
        if (memo['S'] > avg) need['S'] = memo['S'] - avg;
        if (memo['D'] > avg) need['D'] = memo['D'] - avg;
        if (memo['F'] > avg) need['F'] = memo['F'] - avg;
        int len = need['A'] + need['S'] + need['D'] + need['F'];
        if (len == 0) return 0; // 平衡，不需要更新字串
        // 滑动窗口法
        int left = 0, right = 0;
        unordered_map<char, int> window; // 记录窗口里字符个数
        int ans = s.size();
        for (; right < s.size(); right++) // right++ 扩大窗口 
        {
            window[s[right]]++; // 新字符入窗
            while (window['A'] >= need['A'] 
                && window['S'] >= need['S'] 
                && window['D'] >= need['D'] 
                && window['F'] >= need['F']) // 符合条件，缩小窗口直到不符合
            {
                ans = min(ans, right - left + 1);
                window[s[left]]--;
                left++; // 缩小窗口, 窗口左边界右移
            }
        }
        
        return ans;
    }
};
// @lc code=end

