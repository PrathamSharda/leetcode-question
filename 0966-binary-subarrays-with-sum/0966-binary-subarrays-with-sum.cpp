class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int total=0;
        int left=0;
        int sum=0;
        int zero=0;
        for(int i=0;i<nums.size();i++)
        {
            
            sum+=nums[i];
            if(sum>goal)
            {
                zero=0;
                while(sum>goal&&left<i)
                {
                    sum-=nums[left];
                    left++;
                }
                

            }
            if(sum==goal)
            {
                while(nums[left]==0&&left<i)
                {
                    zero++;
                    left++;
                }
                total+=zero+1;
            }
        }
        return total;
    }
};