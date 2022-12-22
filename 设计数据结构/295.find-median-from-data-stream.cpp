/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (large.size() >= small.size())
        {
            large.push(num);
            int a = large.top();
            large.pop();
            small.push(a);
        }
        else
        {
            small.push(num);
            int a = small.top();
            small.pop();
            large.push(a);
        }
    }
    
    double findMedian() {
        if (large.size() > small.size())
        {
            return large.top();
        }
        else if (large.size() < small.size())
        {
            return small.top();
        }
        else
        {
            return (large.top() + small.top()) / 2.0;
        }
        
    }

private:
    priority_queue<int, vector<int>, greater<int>> large; //小顶堆
    priority_queue<int, vector<int>, less<int>> small; //大顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

