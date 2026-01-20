class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>>ans(100,vector<int>(0,0));

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
           // cout<<it.first<<" "<<it.second<<endl;   
            ans[it.second].push_back(it.first);
        }
        vector<int>output;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i].size()!=0&&k!=0)
            {
                for(int it:ans[i])
                {
                    if(k==0)break;
                    k--;
                    output.push_back(it);
                }
                
            }else if (k==0)break;
        }
        return output;
    }
};