/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:

    bool check255(string& s) {
        // printf("check255 %s\n", s.c_str());
        int c = stoi(s);
        if (c > 255) return false;
        return true;
    }

    bool check0(string& s) {
        // printf("check0 %s\n", s.c_str());
        // 00  这种不合法
        if (s.size() > 1 && stoi(s) == 0)
            return false;
        // 001 012 这种不合法
        if (s.size() > 1 && s[0] == '0' && stoi(s) != 0) 
            return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.size() < 4 || s.size() > 12) {
            return {};
        }
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                for (int k = 1; k < 4; k++) {
                    string part1 = s.substr(0, i);
                    if ((i + j) > s.size()) continue;
                    string part2 = s.substr(i, j);
                    if ((i + j + k) > s.size()) continue;
                    string part3 = s.substr(i + j, k);
                    string part4 = s.substr(i + j + k);

                    if (part4.empty() || part4.size() > 3) {
                        continue;
                    }
                    bool a = check0(part1) && check0(part2) && check0(part3) && check0(part4);
                    bool b = check255(part1) && check255(part2) && check255(part3) && check255(part4);
                    if (a && b) {
                        ans.push_back(part1 + "." + part2 + "." + part3 + "." + part4);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

