# 合并区间

#### *Merge Intervals*

给出一个区间的集合，请合并所有重叠的区间。


英文题目:

Given a collection of intervals, merge all overlapping intervals.


**example 1**

```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**example 2**

```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```


---

### 思路

1. 遍历vector，通过start和end找到合并的位置
2. 合并后需要判断是否需要和前后项继续合并(递归完成)


### 代码
```

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<Interval> result;
		bool isDeep = false;
		for (int i = 0; i < intervals.size(); ++i)
		{
			bool isMerge = false;
			for (int j = 0; j < result.size(); ++j)
			{
				int a = intervals[i].start, b = intervals[i].end;
				int c = result[j].start, d = result[j].end;

				if ((a >= c && a <= d) || (b >= c && b <= d) || (a < c && b > d))
				{
					isMerge = true;
					isDeep = true;
					result[j].start = std::min(a, c);
					result[j].end = std::max(b, d);
				}

				if (isMerge)
					break;
			}
			if (!isMerge)
				result.push_back(intervals[i]);
		}
		if (isDeep)
			return merge(result); //intervals无序的情况下，需要再次merge
		else
			return result;
	}
};

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)