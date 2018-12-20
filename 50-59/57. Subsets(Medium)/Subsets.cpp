/************************************************************************/
/* 

Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

*/
/************************************************************************/



#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> prev = { {} };
		vector<vector<int>> combition;
		for (auto n : nums)
		{
			combition.clear();
			for (auto p : prev)
			{
				vector<int> tmp(p);
				tmp.push_back(n);
				combition.push_back(tmp);
			}
			prev.insert(prev.begin(), combition.begin(), combition.end());
		}
		return prev;
	}
};


int main()
{
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> result = Solution().subsets(nums);
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << "[" << result[i][j] << " ";
		}
		cout << "]" << endl;
	}
	return 0;
}