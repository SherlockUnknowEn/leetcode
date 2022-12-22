/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pst;
        path += "/";
        string tmp = "";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                // cout << " tmp= " << tmp << endl;
                if (tmp.size() <= 0) {
                    continue;
                }
                if (tmp == "..") {
                    if (!pst.empty())
                        pst.pop();
                } else if (tmp == ".") {

                }
                else {
                    pst.push(tmp);
                }
                tmp = "";
            } 
            else {
                tmp += path[i];
            }
        }
        string ans = "";
        while (!pst.empty()) {
            // cout << pst.top() << endl;
            ans = "/" + pst.top() + ans;
            pst.pop();
        }
        return ans.size() == 0 ? "/" : ans;
    }
};
// @lc code=end

