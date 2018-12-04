# 最大子序列和

#### *Maximum Subarray*

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

*进阶:*

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。


英文题目:

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.


**example 1**

```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

*Follow up:*
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


---

### 思路

1. 循环遍历nums，加入sum。如果sum小于0， 不管下一个数是正是负，肯定会比这个数加上sum的值大，抛弃之前的sum，sum归为0
2. max记录遍历过程中，出现的sum最大值


### 代码
```

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int max = INT_MIN;
		for (int i = 0; i < nums.size(); ++i)
		{
			sum += nums[i];
			if (sum > max)
				max = sum;
			if (sum < 0)
				sum = 0;
		}
		return max;
	}
}
```

本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)