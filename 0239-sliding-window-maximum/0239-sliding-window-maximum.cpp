class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }
        result.push_back(pq.top().first);
        int p1=1;
        int p2=k;
        while(p2<nums.size())
        {
            pq.push({nums[p2],p2});
            while(pq.top().second<p1)
            {
                pq.pop();
            }
            result.push_back(pq.top().first);
            p1++;
            p2++;
        }
        return result;
    }
};