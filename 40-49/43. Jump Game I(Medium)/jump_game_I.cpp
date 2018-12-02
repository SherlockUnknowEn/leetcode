#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
#define MAX(a, b) ((a) > (b) ? (a): (b))
		int farthest = 0;
		int next = nums[0];
		for (int i =0; i < nums.size() - 1; ++i)
		{
			farthest = MAX(farthest, i + nums[i]);
			if (farthest >= nums.size())
				return true;
			if (i == next)
			{
				next = farthest;
				if (next == i)
					return false;
			}
		}
		return true;
	}
};

int main(int argc, char* argv)
{
	vector<int> nums1 = { 3,2,1,0,4 }; //false
	vector<int> nums2 = { 2,3,1,1,4 }; //true
	cout << Solution().canJump(nums1) << endl;
	return 0;
}