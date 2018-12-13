# 加一

#### *Plus One*

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

英文题目:

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

**example 1**

```
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

```

**example 2**

```
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

```


---

### 思路

1. 从个位开始，加一，若大于十，进位
2. 考虑某个位置的值为9的情况，加一后置零，进位


### 代码
```

#include <vector>
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


```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)