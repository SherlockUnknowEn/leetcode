/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */

// @lc code=start

// bool operator < (const vector<int>& v1, const vector<int>& v2)
// {
//     int len1 = (v1[1] - v2[0])/2;
//     int len2 = (v2[1] - v2[0])/2;
//     if (len1 == len2)
//     {
//         return v1[0] > v2[0]; // 长度相同，返回索引小的
//     }
    
//     return len1 < len2;
// }

class ExamRoom {
public:
    ExamRoom(int n) {
        pushOne(-1, n);
        N = n;
    }
    
    int seat() {
        vector<int> t = heap.top();
        heap.pop();
        int i = 0;
        if (t[0] == -1) // -1 N 坐了人
        {
            i = 0;
        }
        else if (t[1] == N) // 0 N 坐了人
        {
            i = N - 1;
        }
        else
        {
            i = (t[1] - t[0])/2; // 坐的位置
        }
        printf("%d %d %d\n", t[0], t[1], i);
        left.erase(left.find(t[0]));
        right.erase(right.find(t[1]));
        pushOne(t[0], i);
        pushOne(i, t[1]);
        return i;
    }
    
    void leave(int p) {
        vector<int> l = right[p];
        vector<int> r = left[p];
        vector<int> n = merge(l, r);
        left.erase(left.find(p));
        right.erase(right.find(p));
        removeOne(l[0], l[1]);
        removeOne(r[0], r[1]);
        left[n[0]] = n;
        right[n[1]] = n;
    }

    vector<int> merge(const vector<int>& l, const vector<int>& r) const
    {
        vector<int> n(2);
        n[0] = l[0];
        n[1] = r[1];
        return n;
    }

    void removeOne(int l, int r)
    {
        vector<vector<int>> temp;
        while (!heap.empty() && !(heap.top()[0] == l && heap.top()[1] == r))
        {
            temp.push_back(heap.top());
            heap.pop();
        }
        if (!heap.empty() && (heap.top()[0] == l && heap.top()[1] == r))
        {
            heap.pop();
        }
        for ( vector<int> v : temp)
        {
            heap.push(v);
        }
    }

    void pushOne(int l, int r)
    {
        vector<int> d(2);
        d[0] = l;
        d[1] = r;
        heap.push(d);
        left[l] = d;
        right[r] = d;
    }

    struct cmp
    {
        bool operator () (const vector<int>& v1, const vector<int>& v2)
        {
            int len1 = (v1[1] - v2[0])/2;
            int len2 = (v2[1] - v2[0])/2;
            if (len1 == len2)
            {
                return v1[0] > v2[0]; // 长度相同，返回索引小的
            }
            
            return len1 < len2;
        }
    };
    
    

private:
    priority_queue<vector<int>, vector<vector<int>>, cmp> heap; // 大顶堆
    // priority_queue<vector<int>> heap; // 大顶堆
    unordered_map<int, vector<int>> left; // 以 p 为左端点的线段
    unordered_map<int, vector<int>> right; // 以 p 为右端点的线段
    int N;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

