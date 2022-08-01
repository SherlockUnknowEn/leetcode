/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 对于某个状态来说，有8种选择， 4个位置其中一个，+1或者-1
        queue<string> q;
        set<string> visited;
        set<string> deads(deadends.begin(), deadends.end());
        int count = 0;
        q.push("0000");
        visited.insert("0000");
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                string a = q.front();
                q.pop();
                if (a == target)
                {
                    return count;
                }
                if (deads.count(a) != 0)
                {
                    continue;
                }
                
                for (int j = 0; j < 4; j++)
                {
                    string po = plusOne(a, j);
                    if (visited.count(po) == 0) 
                    {
                        q.push(po);
                        visited.insert(po);
                    }
                    

                    string mo = minusOne(a, j);
                    if (visited.count(mo) == 0) 
                    {
                        q.push(mo);
                        visited.insert(mo);
                    }
                    
                }
                
            }
            count++;
        }
        return -1;
    }
    // ["8887","8889","8878","8898","8788","8988","7888","9888"]\n"8888"

    string plusOne(string s, int index) const { // 需要副本  不传引用
        if (s[index] == '9')
        {
            s[index] = '0';
        }
        else
        {
            s[index] += 1;
        }
        return s;
    }

    string minusOne(string s, int index) const {
        if (s[index] == '0')
        {
            s[index] = '9';
        }
        else
        {
            s[index] -= 1;
        }
        return s;
    }
};
// @lc code=end

