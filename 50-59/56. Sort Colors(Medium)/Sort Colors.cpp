/************************************************************************/
/* 

Sort Colors

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

*/
/************************************************************************/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int a = 0, b = 0, c = nums.size() - 1;
		while (b <= c)
		{
			if (nums[b] == 0)
				std::swap(nums[a++], nums[b++]);
			else if (nums[b] == 1)
				b++;
			else
				std::swap(nums[b], nums[c--]);
		}
	}
};

int main()
{
	vector<int> nums = { 2,0,2,1,1,0 };
	Solution().sortColors(nums);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
	return 0;
}