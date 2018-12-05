#include <vector>
#include <iostream>
using namespace std;


/************************************************************************/
/* 
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],     
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]                                                                     
*/
/************************************************************************/


// 解决思路1: 先转置，再水平翻转
//[1, 2, 3],
//[4, 5, 6],    ->   
//[7, 8, 9]
//
//
//[1, 4, 7],
//[2, 5, 8],    ->
//[3, 6, 9]
//
//[7, 4, 1],
//[8, 5, 2], 
//[9, 6, 3]


// 解决思路2: 先垂直翻转，再转置, 好处是可以用标准库std::reverse函数进行垂直翻转
//[1, 2, 3],
//[4, 5, 6],    ->   
//[7, 8, 9]
//
//
//[7, 8, 9],
//[4, 5, 6],    ->
//[1, 2, 3]
//
//[7, 4, 1],
//[8, 5, 2], 
//[9, 6, 3]


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		std::reverse(matrix.begin(), matrix.end());

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = i + 1; j < matrix.size(); j++)
			{
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};


int main(int argc, char* argv[])
{
	vector<vector<int>> matrix = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};

	std::vector<std::vector<int>> matrix2 = {
		{5, 1, 9,11},
		{2, 4, 8,10},
		{13, 3, 6, 7},
		{15,14,12,16}
	};

	Solution().rotate(matrix2);
	for (int i = 0; i < matrix2.size(); ++i)
	{
		for (int j = 0; j < matrix2[i].size(); ++j)
		{
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}