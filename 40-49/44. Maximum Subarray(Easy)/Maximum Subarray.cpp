
/************************************************************************/
/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

*/
/************************************************************************/

#include <vector>
#include <iostream>
using namespace std;

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

	//能A 但时间复杂度较高
	/*int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		for (int i = 0; i < nums.size(); ++i)
		{
			int init = 0;
			for (int j = i; j < nums.size(); ++j)
			{
				init += nums[j];
				sum = init > sum ? init : sum;
			}
		}
		return sum;
	}*/
};

int main(int argc, char* argv[])
{
	vector<int> nums = { -2, -1, 0};
	int max = Solution().maxSubArray(nums);
	cout << max << endl;
	return 0;
}