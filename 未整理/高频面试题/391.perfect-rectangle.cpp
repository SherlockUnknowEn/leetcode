/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1 = INT_MAX;
        int x2 = INT_MIN;
        int y1 = INT_MAX;
        int y2 = INT_MIN;
        for (int i = 0; i < rectangles.size(); i++)
        {
            x1 = min(rectangles[i][0], x1);
            y1 = min(rectangles[i][1], y1);
            x2 = max(rectangles[i][2], x2);
            y2 = max(rectangles[i][3], y2);
        }
        long area = 0;
        set<string> cood;
        for (int i = 0; i < rectangles.size(); i++)
        {
            int xi = rectangles[i][0];
            int yi = rectangles[i][1];
            int ai = rectangles[i][2];
            int bi = rectangles[i][3];
            vector<string> temp;
            temp.push_back(to_string(xi) + "," + to_string(yi));
            temp.push_back(to_string(xi) + "," + to_string(bi));
            temp.push_back(to_string(ai) + "," + to_string(yi));
            temp.push_back(to_string(ai) + "," + to_string(bi));
            for (string k : temp)
            {
                if (cood.count(k) != 0)
                    cood.erase(k);
                else
                    cood.insert(k);
            }
            area += long(ai-xi) * long(bi-yi);
        }
        
        if (area != long(y2-y1) * long(x2-x1)) // 面积与最大矩形不一致
            return false;        
        // 考虑顶点，必须仅为4个
        if (cood.size() != 4) return false;
        // 考虑顶点： 矩形4个顶点 必须在s中
        if (cood.count(to_string(x1) + "," + to_string(y1)) == 0) return false;
        if (cood.count(to_string(x1) + "," + to_string(y2)) == 0) return false;
        if (cood.count(to_string(x2) + "," + to_string(y1)) == 0) return false;
        if (cood.count(to_string(x2) + "," + to_string(y2)) == 0) return false;

        return true;
    }
};
// @lc code=end

