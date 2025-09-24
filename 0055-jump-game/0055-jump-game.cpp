class Solution {
public:
    bool canJump(vector<int>& nums) {
        priority_queue<pair<int,int>>pq;
        unordered_set<int>vis;
        pq.push({nums[0],0});
        int index=0;
        int lastIndex=-1;
        while(index!=nums.size()-1)
        {
            if(pq.empty())return false;
            auto it=pq.top();
            
            index=pq.top().second;
            
            pq.pop();
           
            if(lastIndex>it.second)continue;
            lastIndex=index;
           
            if(index+it.first>=nums.size()-1)
            {
                break;
            }
            for(int i=index+1;i<=(index+it.first);i++)
            {
               
                 if(vis.find(i)!=vis.end())continue;
                 vis.insert(i);
                  pq.push({nums[i],i});
            }
        }
        return true;
    }
};