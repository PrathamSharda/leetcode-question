class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>hash;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            
            hash[nums[i]]++;
            maxi=max(hash[nums[i]],maxi);
        }
        vector<vector<int>>hash2(maxi+1,vector<int>());
        for(auto it:hash)
        {
            hash2[it.second].push_back(it.first);
        }
         
        vector<int>output;
        int i=hash2.size()-1;
        while(k>0)
        {
            if(hash2[i].size()!=0)
            {
                output.insert(output.end(),hash2[i].begin(),hash2[i].end());
                k-=hash2[i].size();
            }
            i--;
        }
        return output;
    }
};