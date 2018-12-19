# 颜色排序

#### *Sort Colors*

给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？


英文题目:

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Follow up:

* A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
* Could you come up with a one-pass algorithm using only constant space?

**example 1**

```
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

```

---

### 思路

1. 容易想到的思路，计数排序，需要循环两次：一次计数，一次赋值
2. 只循环一次的思路：使用b来遍历数组，a初始指向数组首位，c指向数组末尾。
   1). 若循环中b遇到0，交换a,b元素的值，a位置向后移动一位，b继续循环
   2). 若循环中b遇到1，则直接继续循环
   3). 若循环中b遇到2，交换b,c元素的值，c的位置向前移动一位，而此时不能确定交换后b的值是1还是0，b位置保持不动
   
3. 上述过程只需要循环一次，可以将0往前放，2往后放，1留在中间



### 代码
```

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

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)