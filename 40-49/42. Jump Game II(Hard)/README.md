# 跳跃游戏2

#### *Jump Game II*

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

**说明:**

1. 假设你总是可以到达数组的最后一个位置。


英文题目:

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

**note:**

1. You can assume that you can always reach the last index.


**example 1**

```
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
```


---

### 思路

1. 循环遍历数组，使用farthest保存当前最远可到达的距离
2. next为当前步数可达到的距离，到达next后，step加1
3. 到达next之前，farthest的更新不影响已花费的步数step，到达next后，下一个next等于这过程中寻找到的farthest


### 代码
```

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

```
本题以及其它leetcode题目代码github地址: [github地址](https://github.com/SherlockUnknowEn/leetcode)