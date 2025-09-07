class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<> >pq;

        unordered_map<int,int>mp;
        for(auto it:hand)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            pq.push(it);
        }

        while(!pq.empty())
        {
            if(pq.size()<groupSize)return false;
            vector<int>nums;
            vector<int>f;
            for(int i=0;i<groupSize;i++)
            {
                auto [num,freq]=pq.top();
                pq.pop();
                nums.push_back(num);
                f.push_back(freq-1);
            }
            for(int i=0;i<groupSize;i++)
            {
                if(i!=0&&nums[i]-nums[i-1]!=1)
                {
                    return false;
                }

            }
            for(int i=0;i<groupSize;i++)
            {
                if(f[i]==0)continue;

                pq.push({nums[i],f[i]});
            }
        }
        return true;


    }
};