/************************************************************************/
/* 

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/
/************************************************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() <= 0)
			return false;
		vector<vector<char>> cannot(board.size(), vector<char>(board[0].size()));
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (go2(board, i, j, cannot, word, 0))
					return true;
			}
		}
		return false;
	}
private:
	bool go2(const vector<vector<char>>& board, int i, int j, vector<vector<char>>& cannot, const string& word, int index)
	{
		if (index >= word.length())
			return true;
		if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || cannot[i][j] == 1)
			return false;
		if (board[i][j] != word[index])
			return false;
		cannot[i][j] = 1; //此路走过
		if (go2(board, i - 1, j, cannot, word, index + 1) //up
			|| go2(board, i + 1, j, cannot, word, index + 1) //donw
			|| go2(board, i, j - 1, cannot, word, index + 1) //left
			|| go2(board, i, j + 1, cannot, word, index + 1)) //right
			return true;
		cannot[i][j] = 0; //回溯
		return false;

	}
};

int main()
{
	/*vector<vector<char>> board = { 
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};*/

	vector<vector<char>> board = {
		{ 'C','A','A' },
		{ 'A','A','A', },
		{ 'B','C','D' }
	};
	bool exists = Solution().exist(board, "AAB");
	cout << exists << endl;
	return 0;
}
