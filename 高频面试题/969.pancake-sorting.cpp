/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */

// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> re;
        sort(arr, 0, arr.size(), re);
        return re;
    }

    void sort(vector<int>& arr, int start, int end, vector<int>& re)
    {
        if (start >= end)
            return;
        
        int index = 0;
        for (int i = start; i < end; i++)
        {
            index = arr[i] > arr[index] ? i : index;
        }
        if (index != end - 1) // 最长的在最底上 直接跳过
        {
            if (index != 0) // 最长的在最顶上 直接翻转到最底下
            {
                re.push_back(index + 1);
                flip(arr, start, index + 1);
            }
            re.push_back(end);
            flip(arr, start, end);
        }
        sort(arr, start, end - 1, re);
    }

    void flip(vector<int>& arr, int start, int end)
    {
        end--;
        while (start <= end)
        {
            int a = arr[start];
            arr[start] = arr[end];
            arr[end] = a;
            start++;
            end--;
        }
    }
};
// @lc code=end

