#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

//时间复杂度O(n²)
class SolutionDP {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1)
			return 0; 
		vector<int> steps;
		for (int i = nums.size() - 2; i >= 0; --i)
		{
			if (nums[i] >= nums.size() - 1 - i)
			{
				//此位置能达到最终点
				vector<int> next_nums;
				for (int j = 0; j <= i; ++j)
					next_nums.push_back(nums[j]);
				steps.push_back(1 + jump(next_nums));
			}
		}
		sort(steps.begin(), steps.end());
		return steps[0];
	}
};

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;
#define MAX(a, b) ((a) > (b) ? (a): (b))
		int step = 1; //已经花费的步数
		int next = nums[0]; //到达next时step+1
		int farthest = 0; //可以到达的最远地方
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			farthest = MAX(farthest, i + nums[i]);
			if (i == next)
			{
				step++;
				next = farthest;
			}
		}
		return step;
	}
};

int main(int argc, char* argv[])
{
	vector<int> nums = { 2,3,1,1,4 }; // 2
	vector<int> nums1 = { 8,4,3,4,0,0,9,7,2,3,5,7,3,1,1,5,1,8,6,1,1,6,1,1,8,0,4 }; //5
	int step = Solution().jump(nums1);
	cout << step << endl;
	return 0;
}