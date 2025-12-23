class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>output;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0&&nums[i]==nums[i-1])continue;
            int p1=i+1;
            int p2=nums.size()-1;
            while(p1<p2)
            {
                if(nums[i]+nums[p1]+nums[p2]==0)
                {
                    output.push_back({nums[i],nums[p1],nums[p2]});

                    p1++;
                    p2--;
                    while (p1 < p2 && nums[p1] == nums[p1 - 1]) p1++; 
                    while (p1 < p2 && nums[p2] == nums[p2 + 1]) p2--; 
                    
                    
                }
                else if (nums[i]+nums[p1]+nums[p2]<0)
                {
                    p1++;
                }else{
                    p2--;
                }

            }
        }
        // vector<vector<int>>result;
        // for(auto it:output)
        // {
        //     result.push_back(it);
        // }
        return output;
    }
};