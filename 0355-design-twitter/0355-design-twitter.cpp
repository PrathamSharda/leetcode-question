class Twitter {
    unordered_map<int,vector<pair<int,int>> >tweets;
    unordered_map<int,unordered_set<int>>followers;
    int time=0;
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>> >pq;
        vector<int>PostData;
        for(auto it:followers[userId])
        {
            PostData.push_back(it);
        }      
        PostData.push_back(userId);

        for(int i=0;i<PostData.size();i++)
        {
            if(tweets[PostData[i]].size()==0)continue;
            int n = (int)tweets[PostData[i]].size();
            int size= tweets[PostData[i]].size()>10?10:tweets[PostData[i]].size();

            for(int j=n-1;j>=n-size;j--)
            {
                pq.push(tweets[PostData[i]][j]);
            }
        }
        vector<int>result;
            int k=10;
            while(k&&!pq.empty())
            {
                k--;
                auto it=pq.top();
                result.push_back(it.second);
                pq.pop();

            }
            return result;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {

            followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */