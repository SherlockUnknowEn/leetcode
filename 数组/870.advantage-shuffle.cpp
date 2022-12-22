/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */


// @lc code=start
class Solution {
public:
    struct Pair1 //运算符重载 <
    {
        int index;
        int val;
        Pair1(int a, int b) { index = a; val = b; }
        bool operator< (const Pair1& a) const
        {
            return val < a.val; // 大顶堆
        }
    };

    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> res(n);
        sort(nums1.begin(), nums1.end()); // 对nums1排序
        int large = n - 1;
        int small = 0;

        priority_queue<Pair1> q;
        for (int i = 0; i < n; i++)
        {
            q.push(Pair1(i, nums2[i]));
        }
        
        for (int i = n-1; i >= 0; --i)
        {
            Pair1 t = q.top();
            q.pop();
            if (nums1[large] > t.val) // advantage
            {
                res[t.index] = nums1[large];
                large--;
            }
            else
            {
                res[t.index] = nums1[small];
                small++;
            }
        }
        
        return res;
    }
};
// @lc code=end

