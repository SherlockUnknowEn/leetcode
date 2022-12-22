/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        goPath(graph, 0, res, path);
        return res;
    }

    void goPath(const vector<vector<int>>& graph, int index, vector<vector<int>>& res, vector<int>& path)
    {
        if (index >= graph.size()) return;
        path.push_back(index);
        if (index == (graph.size() - 1))
        {
            res.push_back(path);
            path.pop_back(); // 除此之外可能还有别的路径
            return;
        }
        for (int i = 0; i < graph[index].size(); i++)
        {
            goPath(graph, graph[index][i], res, path);
        }
        path.pop_back();
    }


};
// @lc code=end

