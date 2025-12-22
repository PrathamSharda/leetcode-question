class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag=0;
        int p1=-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
            {
                flag=1;
                p1=i;
                break;
            }
        }

        if(flag)
        {
            sort(nums.begin()+p1+1,nums.end());
            for(int i=p1+1;i<nums.size();i++)
            {
                if(nums[i]>nums[p1])
                {
                    int temp=nums[i];
                    nums[i]=nums[p1];
                    nums[p1]=temp;
                    break;
                }
            }
        }
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};