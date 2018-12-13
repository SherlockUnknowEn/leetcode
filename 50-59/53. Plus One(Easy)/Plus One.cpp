/************************************************************************/
/* 

Plus One

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/
/************************************************************************/


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int m = digits.size();
		for (int i = m - 1; i >= 0; --i)
		{
			if (digits[i] < 9)
			{
				++digits[i];
				return digits;
			}
			else
				digits[i] = 0;
		}
		// 到此处仍未return digits所有元素为9
		vector<int> result(digits.size() + 1);
		result[0] = 1;
		return result;
	}
};

int main()
{
	vector<int> digits = { 1, 2, 3 };
	vector<int> result = Solution().plusOne(digits);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i];
	}
	return 0;
}