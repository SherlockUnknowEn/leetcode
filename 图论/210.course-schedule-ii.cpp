/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    // BFS 解法
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        genGraph(prerequisites, graph, indegree);
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0) // 如果 i 课程入度为0
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            res.push_back(c);
            // TODO: 前置课程需要c的，入度减一
            for (int i = 0; i < graph[c].size(); i++)
            {
                int o = graph[c][i];
                indegree[o]--;
                if (indegree[o] == 0)
                {
                    q.push(o);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }

    void genGraph(const vector<vector<int>>& prerequisites, vector<vector<int>>& graph, vector<int>& indegree)
    {
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            graph[from].push_back(to);
            indegree[to]++;
        }
    }

};
// @lc code=end

