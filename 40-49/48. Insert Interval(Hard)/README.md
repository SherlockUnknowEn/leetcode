# 插入区间

#### *Insert Interval*

给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。


英文题目:

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.


**example 1**

```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**example 2**

```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```


---

### 思路

1. 如果原区间集合为空，直接插入首位
2. 遍历原区间集合，分为两种情况：
    (1). 需要插入区间在集合中某两个区间之间，则直接插入对应的位置
    (2). 需要插入的区间，和集合中某些区间有交集，则考虑是否合并
3. 因为只需要插入一个区间，所以插入后，将原集合剩余区间元素按顺序补齐


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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;
		bool inserted = false;
		if (intervals.size() == 0)
		{
			result.push_back(newInterval);
			return result;
		}

		for (int i = 0; i < intervals.size(); ++i)
		{
			if (!inserted && newInterval.start <= intervals[i].end && newInterval.end < intervals[i].start)
			{
				result.push_back(newInterval);
				result.push_back(intervals[i]);
				inserted = true;
			}
			else if (!inserted && newInterval.start <= intervals[i].end && newInterval.end >= intervals[i].start)
			{
				Interval tmp;
				tmp.start = std::min(intervals[i].start, newInterval.start);
				tmp.end = std::max(intervals[i].end, newInterval.end);
				int j = i + 1;
				for (; j < intervals.size(); ++j)
				{
					if (newInterval.end >= intervals[j].start)
						tmp.end = std::max(intervals[j].end, newInterval.end);
					else
						break;
				}
				result.push_back(tmp);
				i = j - 1; //i会自增,因此为j-1
				inserted = true;
			}
			else
				result.push_back(intervals[i]);
		}
		//循环结束仍未插入，则插入最后
		if (!inserted)
			result.push_back(newInterval);

		return result;
	}
};

```

本题以及其它leetcode题目代码github地址: [github地址](https:github.com/SherlockUnknowEn/leetcode)