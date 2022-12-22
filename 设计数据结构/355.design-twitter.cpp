/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

class Node {
public:
    Node* next;
    int val;
    int time;
};

class LinkList {
public:
    LinkList()
    {
        head = new Node();
        tail = head;
    }

    void push(Node* n) {

    }

    static Node* mergeN(const vector<LinkList>& lists)
    {
        return nullptr;
    }

private:
    Node* head;
    Node* tail;
}


// @lc code=start
class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (twitters.find(userId) == twitters.end())
            twitters.insert({ userId, LinkList() });
        twitters[userId].push(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        auto users = follows[userId];
        vector<LinkList> lists;
        for (int i = 0; i < users.size(); i++)
        {
            lists.push_back(twitters[users[i]]);
        }
        Node* n = LinkList::mergeN(lists);
        vector<int> f;
        while (n != nullptr)
        {
            f.push(n->val);
            f = f->next;
        }
        return f;
    }
    
    void follow(int followerId, int followeeId) {
        if (follows.find(followerId) == follows.end())
            follows.insert({ followerId, list<int>() });
        follows[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows.find(followerId) == follows.end())
            follows.insert({ followerId, list<int>() });
        follows[followerId].remove(followeeId);
    }

private:
    unordered_map<int, list<int>> follows; // follower -> followee
    unordered_map<int, LinkList> twitters; // userId -> tweetId
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

