class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        vector<int>temp(nums.size(),INT_MIN);
        while(k&&!pq.empty())
        {
            k--;
            auto it=pq.top();
            temp[it.second]=it.first;
            pq.pop();
        }
        vector<int>output;

        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]!=INT_MIN)
            {
                output.push_back(temp[i]);
            }
        }
        return output;

    }
};