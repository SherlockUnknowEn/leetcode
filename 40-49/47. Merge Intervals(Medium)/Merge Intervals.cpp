
/************************************************************************/
/*

//合并区间


Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/
/************************************************************************/


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
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


int main(int argc, char* argv[])
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1, 3)); 
	intervals.push_back(Interval(2, 6));
	intervals.push_back(Interval(8, 10));
	intervals.push_back(Interval(15, 18));
	vector<Interval> result = Solution().merge(intervals);
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << "[" << result[i].start << ", " << result[i].end << "] ";
	}
	return 0;
}