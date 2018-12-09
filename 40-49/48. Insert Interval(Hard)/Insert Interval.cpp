/************************************************************************/
/*

Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


*/
/************************************************************************/


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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


int main(int argc, char* argv[])
{
	
	vector<Interval> intervals;
	intervals.push_back(Interval(1, 3));
	intervals.push_back(Interval(6, 9));

	vector<Interval> result = Solution().insert(intervals, Interval(2, 5));

	for (int i = 0; i < result.size(); ++i)
		cout << "[" << result[i].start << ", " << result[i].end << "] ";


	return 0;
}