# 跳跃游戏1

#### *Jump Game I*

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断是否可以到达数组的最后一个位置。



英文题目:

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.


**example 1**

```
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**example 2**

```
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
```



---

### 思路

1. 参照 [Jump Game II](https://github.com/SherlockUnknowEn/leetcode/tree/master/40-49/42.%20Jump%20Game%20II(Hard)) 此题，只需要改为循环过程中判断是否到达了数组尾部即可


### 代码
```

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
				next = farthest; //已不可前进
				if (next == i)
					return false;
			}
		}
		return true;
	}
};

```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)