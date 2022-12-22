/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // ---   ----    ------
        //  ---       ----
        int fi = 0;
        int si = 0;
        vector<vector<int>> res;
        while (fi < firstList.size() && si < secondList.size())
        {
            vector<int> v1 = firstList[fi];
            vector<int> v2 = secondList[si];
            if (v2[0] > v1[1]) // no overlap
                fi++;
            else if (v2[1] < v1[0])
                si++;
            else
            {
                vector<int> o;
                o.push_back(max(v1[0], v2[0]));
                o.push_back(min(v1[1], v2[1]));
                res.push_back(o);
                if (v1[1] < v2[1])
                    fi++;
                else
                    si++;
            }
        }
        return res;
    }
};
// @lc code=end

