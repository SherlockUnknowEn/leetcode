/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // 1. 排序后直接找 N - K
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];

        // 2. 构建大小为 k 的小顶堆
        // priority_queue<int, vector<int>, greater<int>> q;
        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     if (q.size() < k)
        //     {
        //         q.push(nums[i]);
        //     }
        //     else if (q.top() < nums[i])
        //     {
        //         q.pop();
        //         q.push(nums[i]);
        //     }
        // }
        // return q.top();

        // 3. 快速选择法 (基于快排)
        // 初始选择一个元素，比它小的元素移动到它左边，比它大的元素移动到它右边
        // 查看左边元素个数 是否为 k, 大于 k 继续处理左边元素，小于 k 处理右边元素，等于 k 返回
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = partition(nums, left, right);
            for (size_t i = 0; i < nums.size(); i++)
            {
                printf("%d ", nums[i]);
            }
            printf("ou %d, %d, %d\n", left, right, mid);
            if (k == nums.size() - mid)
            {
                return nums[mid];
            }
            else if (k < nums.size() - mid)
            {
                left = mid + 1;
            }
            else 
            {
                right = mid - 1;
            }
        }
        return -99;
        



        // 4. 数组arr存 k个元素，每次更新最小的那个元素
        // int min = INT_MIN;
        // int idxmin = 0;
        // vector<int> arr(k, INT_MIN);
        // minIndexValue(arr, idxmin, min);
        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] > min)
        //     {
        //         arr[idxmin] = nums[i];
        //         minIndexValue(arr, idxmin, min);
        //     }
        // }
        // return min;

    }

    int partition(vector<int>& arr, int start, int end)
    {
        int v = arr[end];
        while (start < end) 
        {
            while (start < end && arr[start] <= v)
            {
                start++;
            }
            arr[end] = arr[start];
            
            while (start < end && arr[end] >= v) 
            {
                end--;
            }
            arr[start] = arr[end];
        }
        arr[end] = v;
        return end;
    }

    void swap(vector<int>& arr, int i, int j)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    void minIndexValue(const vector<int>& arr, int& index, int& v) {
        v = INT_MAX;
        index = 0;
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[i] < v)
            {
                v = arr[i];
                index = i;
            }   
        }
    }
};
// @lc code=end

