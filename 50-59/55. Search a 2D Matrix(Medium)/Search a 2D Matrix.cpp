/************************************************************************/
/* 

Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
target = 13
Output: false

*/
/************************************************************************/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//binary search
		int m = matrix.size();
		if (m == 0 || matrix[0].size() == 0 || target < matrix[0][0] || target > matrix[m - 1][matrix[0].size() - 1])
			return false;
		int n = matrix[0].size();

		//优化版，两次二分查找
		int i = 0;
		int j = m;
		int start = 0;
		while (i < j)
		{
			int start = (i + j) / 2;
			if (matrix[start][0] == target)
				return true;
			if (matrix[start][0] > target)
				j = start - 1;
			if (matrix[start][0] < target)
				i = start + 1;
		}

		i = ((i - 1) >= 0 ? (i - 1) : 0) * n;
		j = ((j + 1) <= m ? (j + 1) : m) * n;
		while (i <= j)
		{
			int mid = (i + j) / 2;
			if (matrix[mid / n][mid % n] == target)
				return true;
			if (matrix[mid / n][mid % n] > target)
				j = mid - 1;
			if (matrix[mid / n][mid % n] < target)
				i = mid + 1;
		}
		return false;
	}
};

int main(int argc, char* argv[])
{
	vector<vector<int>> matrix = {
		{1,   3,  5,  7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};
	int target = 3;
	bool result = Solution().searchMatrix(matrix, target);
	cout << result;
	return 0;
}